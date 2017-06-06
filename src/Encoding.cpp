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

void MemSteve::HuffmenTree::convert(const std::vector<Letter> letters, std::priority_queue<node*,std::vector<node*>,cmp>& huffmenList) {

    for(auto le: letters) {
        node* newNode = new node(le.getLetter(), le.getCount());
        huffmenList.push(newNode);
    }
//    for(auto le: letters) {
//        huffmenList.push(le);
//    }
    // test
//    while(huffmenList.size()) {
//        node p = huffmenList.top();
//        std::cout<<p.letter
//                 <<":"
//                 <<p.weight
//                 <<"\n";
//        huffmenList.pop();
//    }
}

void::MemSteve::HuffmenTree::construct(std::priority_queue<node*,std::vector<node*>,cmp> &huffmenList) {
    node* __current = nullptr;

    size_t listSize = huffmenList.size();

    if (listSize == 0) {
        return;
    }
    if (listSize == 1 ) {
        node* currentNode = huffmenList.top();
        huffmenList.pop();
        this->root = currentNode;
        return;
    }


    while(huffmenList.size()>1) {
        node* firstNode = huffmenList.top();
        huffmenList.pop();
        node* secondNode = huffmenList.top();
        huffmenList.pop();
        node* combineNode = new node(0,firstNode->weight+secondNode->weight);
        combineNode->left = firstNode;
        combineNode->right = secondNode;
        std::cout<<"left: "<<firstNode->letter<<" right: "<<secondNode->letter<<"\n";
        firstNode->parent = combineNode;
        secondNode->parent = combineNode;
        huffmenList.push(combineNode);
        std::cout<<"Combine:"<< combineNode->weight<<"\n";
    }

    node* topNode = huffmenList.top();
    this->root = topNode;
}




MemSteve::HuffmenTree::~HuffmenTree() {
    if(this->root) {

    }
}



MemSteve::HuffmenTree::HuffmenTree(std::vector<MemSteve::Letter> &letters) {
    std::priority_queue<node*,std::vector<node*>,cmp> huffmenLetters;
    convert(letters, huffmenLetters);
    construct(huffmenLetters);
}

void trav(MemSteve::HuffmenTree::node* a, int counter) {

    if (a->letter != 0) {
        std::cout<<"counter: "<<counter<<" letter: "<<a->letter<<" count: "<<a->weight<<"\n";
    }

    if (a->left) {
        trav(a->left, counter+1);
    }
    if (a->right) {
        trav(a->right, counter+1);
    }

}


void MemSteve::HuffmenTree::traverseTree() {
    node* __current = this->root;
    std::cout<<"test Tree"<<std::endl;
    trav(__current,0);
}





