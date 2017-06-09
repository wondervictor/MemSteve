//
// Created by VicChan on 2017/6/2.
//

#ifndef MEMSTEVE_ENCODING_H
#define MEMSTEVE_ENCODING_H

#include <map>
#include "Counter.h"
#include <queue>

#if WITH_LOG
#define DEBUG 1
#else
#define DEBUG 0
#endif

namespace MemSteve {


    float codeByHuffmen(const std::map<char, int>& letters, const std::string inputString, std::string& outputString, std::map<char, std::string> code, std::string outputFileName, const std::string codeFileName);

    float codeByShannon(const std::map<char, int>& letters, const std::string inputString, std::string& outputString, std::map<char, std::string> code, std::string outputFileName, const std::string codeFileName);

    void decode(const std::string& inputString, std::map<char, std::string>& c, std::string& outputString);


    class Encoder {

    public:

        Encoder();

        Encoder(std::map<char, std::string>& c):code(c){};

        float encode(const std::string& inputString,
                   std::map<char, std::string>& c,
                   std::string& outputString);


        void writeToFile(const std::string& inputString, const std::string& fileName);

        float encode(const std::string& inputString, std::string& outputString);

    private:
        std::map<char, std::string> code;


    };

    // Huffmen Coding
    class HuffmenTree {


    public:
        struct node {
            node* left;
            node* right;
            node* parent;
            float weight;
            char letter;
            node(char le, float we):weight(we),letter(le) {
                left = nullptr;
                parent = nullptr;
                right = nullptr;
            };
            node(char le, float we, node* r, node* p, node* l):weight(we),letter(le),parent(p),left(l),right(r){};
        };

        struct cmp {
            bool operator()(const node* a,const node* b)const {
                return a->weight > b->weight;
            }
        };

        void encode(std::map<char, std::string>& c);
        HuffmenTree()= default;
        HuffmenTree(std::map<char, int>& letters);

        void saveCode(const std::map<char, std::string>& c, const std::string name);
        ~HuffmenTree();

        void traverseTree();




    private:
        node* root;
        void convert(const std::map<char, int>& letters, std::priority_queue<node*,std::vector<node*>,cmp>& huffmenList);
        void construct(std::priority_queue<node*,std::vector<node*>,cmp>& huffmenList);
    };

    // Shannon Coding
    class Shannon {
    public:
        Shannon()= default;
        Shannon(const std::map<char, int>& letters);
        std::map<char, std::string> getShannonCode() const { return code; };
        void encode(const std::map<char, int>& letters);

        void saveCode(const std::map<char, std::string>& c, const std::string name);

    private:
        std::map<char, std::string> code;
    };

    // Shannon-Fano-Elias Coding
    class ShannonFanoElias {
    public:
        ShannonFanoElias()= default;
        ShannonFanoElias(const std::map<char, int>& letters);
        std::map<char, std::string> getShannonFanoEliasCode() const { return code; };
        void encode(const std::map<char, int>& letters);

        void saveCode(const std::map<char, std::string>& c, const std::string name);


    private:
        std::map<char, std::string> code;

    };

}




#endif //MEMSTEVE_ENCODING_H
