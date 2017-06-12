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

    /**
     * @name codeByHuffmen
     * @brief input the string that needs to be encoded by Huffmen
     * @param letters key-value map key:character value:frequency
     * @param inputString string need to be encoded
     * @param outputString encoded string
     * @param code coding result, key-value key:character value: corresponding code
     * @param outputFileName filename of the encoded string
     * @param codeFileName filename of the code map
     * @return code length
     * */
    float codeByHuffmen(const std::map<char, int>& letters,
                        const std::string inputString,
                        std::string& outputString,
                        std::map<char, std::string>& code,
                        std::string outputFileName,
                        const std::string codeFileName);
    /**
     * @name codeByShannon
     * @brief input the string that needs to be encoded by Shannon Coding
     * @param letters key-value map key:character value:frequency
     * @param inputString string need to be encoded
     * @param outputString encoded string
     * @param code coding result, key-value key:character value: corresponding code
     * @param outputFileName filename of the encoded string
     * @param codeFileName filename of the code map
     * @return code length
     * */
    float codeByShannon(const std::map<char, int>& letters,
                        const std::string inputString,
                        std::string& outputString,
                        std::map<char, std::string>& code,
                        std::string outputFileName,
                        const std::string codeFileName);


    /**
     * @name codeByShannonFanoElias
     * @brief input the string that needs to be encoded by S-F-E
     * @param letters key-value map key:character value:frequency
     * @param inputString string need to be encoded
     * @param outputString encoded string
     * @param code coding result, key-value key:character value: corresponding code
     * @param outputFileName filename of the encoded string
     * @param codeFileName filename of the code map
     * @return code length
     * */
    float codeByShannonFanoElias(const std::map<char, int>& letters,
                                 const std::string inputString,
                                 std::string& outputString,
                                 std::map<char, std::string>& code,
                                 std::string outputFileName,
                                 const std::string codeFileName);


    /**
     * @name decode
     * @brief inputString the encoded string that needs to be decode
     * @param outputString encoded string
     * @param code coding result, key-value key:character value: corresponding code
     * @param codeFileName filename of the decoded text
     * */
    void decode(const std::string& inputString, std::map<char, std::string>& code, std::string& outputString, std::string outputFileName);


    /// Encoder: collect the code map and encode the string into compressed string
    class Encoder {

    public:

        Encoder()= default;

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
        // Node of Huffmen Tree
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

        // Comparing function for Priority queue
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

        // dump the huffmen tree by DFS Algorithm
        void traverseTree();

    private:
        node* root;
        // convert the letters (character frequency) into huffmen tree node type
        void convert(const std::map<char, int>& letters, std::priority_queue<node*,std::vector<node*>,cmp>& huffmenList);
        // construct the huffmen tree with nodes and a priority queue
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
