//
// Created by VicChan on 2017/6/2.
//


#include "../include/Encoding.h"
#include <iostream>
#include <cmath>
#include <fstream>


#define LEFT 0
#define RIGHT 1

float MemSteve::codeByHuffmen(const std::map<char, int>& letters, const std::string inputString, std::string outputFileName,const std::string codeFileName) {
    float codeLength = 0.0;
    HuffmenTree huffmenTree(const_cast<std::map<char, int>& >(letters));
    std::map<char, std::string> code;
    huffmenTree.encode(code);
    huffmenTree.saveCode(code,codeFileName);

    Encoder encoder(code);

    std::string outputString;

    codeLength = encoder.encode(inputString,code,outputString);
    std::cout<<outputString<<"\n";

    encoder.writeToFile(outputString, outputFileName);


    return codeLength;
}


float MemSteve::codeByShannon(const std::map<char, int>& letters, const std::string inputString, std::string outputFileName,const std::string codeFileName) {
    float codeLength = 0.0;
    Shannon shannon(letters);
    std::map<char, std::string> code = shannon.getShannonCode();
    Encoder encoder(code);
    shannon.saveCode(code,codeFileName);

    std::string outputString;

    codeLength = encoder.encode(inputString,code,outputString);
    std::cout<<outputString<<"\n";

    encoder.writeToFile(outputString, outputFileName);

    return codeLength;

}

float MemSteve::Encoder::encode(const std::string& inputString,
                              std::map<char, std::string>& code,
                              std::string& outputString) {
    int length = 0;
    int num = 0;
    for(auto i: inputString) {
        if (code[i].size()) {
            num += 1;
            length += code[i].size();
            outputString.append(code[i]);
        }
    }
    return (float)length/num;
}

void MemSteve::Encoder::writeToFile(const std::string &inputString, const std::string &fileName) {

    std::ofstream outputFile(fileName, std::ios::binary);
    outputFile << inputString;
    outputFile.close();
}

void __saveCode(const std::map<char, std::string>& c, const std::string name) {
    std::ofstream outputFile(name, std::ios::binary);
    std::map<char, std::string>::iterator iter = const_cast<std::map<char, std::string>& >(c).begin();
    for(; iter != c.end(); iter ++) {
        char s[20];
        sprintf(s,"%c:%s\n",iter->first,iter->second.c_str());
        outputFile << s;
    }
    outputFile.close();
}


float MemSteve::Encoder::encode(const std::string& inputString,
                              std::string& outputString) {
    return this->encode(inputString,this->code,outputString);
}

void replace(std::string& s, const std::string& toReplace, const std::string replaceWith) {
    size_t f = s.find(toReplace);
    s.replace(f, toReplace.length(), replaceWith);
}

void decode(const std::string& inputString, std::map<char, std::string>& c, std::string& outputString) {
    outputString = inputString;
    std::map<char, std::string>::iterator iter = c.begin();
    for(; iter != c.end(); iter ++) {
        std::string p;
        p.push_back(iter->first);
        replace(outputString,iter->second,p);
    }
}


void traverseWithCode(MemSteve::HuffmenTree::node* root, std::string previousCode, int flag, std::map<char, std::string> &c) {
    previousCode.push_back(flag==RIGHT ? '1':'0');
    if (root->letter != 0) {
        c[root->letter] = previousCode;
    }
    if (root->right) {
        traverseWithCode(root->right, previousCode, RIGHT,c);
    }
    if (root->left) {
        traverseWithCode(root->left, previousCode, LEFT,c);
    }
}

void MemSteve::HuffmenTree::encode(std::map<char, std::string> &c) {
    traverseWithCode(this->root->right,"",RIGHT, c);
    traverseWithCode(this->root->left,"",LEFT, c);
}

void MemSteve::HuffmenTree::convert(const std::map<char, int>& letters, std::priority_queue<node*,std::vector<node*>,cmp>& huffmenList) {


    std::map<char, int>::iterator iter = const_cast<std::map<char, int>& >(letters).begin();
    for(; iter != letters.end(); iter ++)  {
        node* newNode = new node(iter->first, iter->second);
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
//        std::cout<<"left: "<<firstNode->letter<<" right: "<<secondNode->letter<<"\n";
        firstNode->parent = combineNode;
        secondNode->parent = combineNode;
        huffmenList.push(combineNode);
//        std::cout<<"Combine:"<< combineNode->weight<<"\n";
    }

    node* topNode = huffmenList.top();
    this->root = topNode;
}

void MemSteve::HuffmenTree::saveCode(const std::map<char, std::string> &c, const std::string name) {
    __saveCode(c,name);
}

static void deleteHuffmanNode(MemSteve::HuffmenTree::node* root) {
    if (root->right) {
        deleteHuffmanNode(root->right);
    }
    if (root->left) {
        deleteHuffmanNode(root->left);
    }
    delete root;
}


MemSteve::HuffmenTree::~HuffmenTree() {
    if(this->root) {
        deleteHuffmanNode(root);
    }
}



MemSteve::HuffmenTree::HuffmenTree(std::map<char, int> &letters) {
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


MemSteve::Shannon::Shannon(const std::map<char, int> &letters) {
    encode(letters);
}


bool cmp(const std::pair<char, float>& a, const std::pair<char, float>& b) {
    return a.second < b.second;
}

int getFloatBinary(float& num) {
    num = num * 2;
    return (int)(num);
}

void MemSteve::Shannon::encode(const std::map<char, int> &letters) {
    int sum = 0;
    std::vector<std::pair<char, float> > letterList;
    std::map<char, int>::iterator iter = const_cast<std::map<char, int>& >(letters).begin();
    for(; iter != letters.end(); iter ++)  {
        sum += iter->second;
        std::pair<char, float> p(iter->first, iter->second);
        letterList.push_back(p);
    }

    std::sort(letterList.begin(),letterList.end(),cmp);
    float currentProb = 0;
    std::vector<std::pair<char, float> >::iterator listIter = letterList.begin();
    for(; listIter != letterList.end(); listIter ++) {
        int length = (int)ceilf(log2f((float)sum/listIter->second));//ceil(log2f(sum/iter->second));
        std::string __code;
        float prob = currentProb;
        while(length) {
            length --;
            __code.push_back(getFloatBinary(prob) ? '1':'0');
        }
        code[listIter->first] = __code;
        currentProb += (float)listIter->second/sum;
    }
}

void MemSteve::Shannon::saveCode(const std::map<char, std::string> &c, const std::string name) {
    __saveCode(c,name);
}



