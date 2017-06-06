//
// Created by VicChan on 2017/6/2.
//


#include "../include/Encoding.h"
#include <iostream>


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


void MemSteve::HuffmenTree::encode(std::map<char, std::string> &c) {


}

void MemSteve::HuffmenTree::convert(const std::vector<Letter> letters, std::priority_queue<Letter>& huffmenList) {
    for(auto le: letters) {
        huffmenList.push(le);
    }
    // test
    while(huffmenList.size()) {
        Letter p = huffmenList.top();
        std::cout<<p.getCount();
    }
}



MemSteve::HuffmenTree::HuffmenTree(std::vector<MemSteve::Letter> &letters) {
    std::priority_queue<MemSteve::Letter> huffmenLetters;
    convert(letters, huffmenLetters);
}





