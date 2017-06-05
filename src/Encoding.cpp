//
// Created by VicChan on 2017/6/2.
//


#include "../include/Encoding.h"


float MemSteve::codeByHuffmen(const std::vector<Letter>& letters,
                              std::map<char, std::string> code,
                              std::string outputFileName) {
    float codeLength = 0.0;



    return codeLength;
}


float MemSteve::codeByShannon(const std::vector<Letter>& letters,
                              std::map<char, std::string> code,
                              std::string outputFileName) {
    float codeLength = 0.0;

    return codeLength;
}

int MemSteve::Encoder::encode(const std::string& inputString,
                              const std::map<char, std::string>& c,
                              std::string& outputString) {
    int length = 0;



    return length;
}

int MemSteve::Encoder::encode(const std::string& inputString,
                              std::string& outputString) {
    return this->encode(inputString,this->code,outputString);
}


namespace MemSteve {
    class HuffmenTree {

        struct node {
            node* left;
            node* right;
            node* parent;
            float weight;
            char letter;
        };

    public:

        void encode(std::map<char, std::string>& c);

    private:
        node* root;

    };

}



