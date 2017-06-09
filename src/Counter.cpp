//
// Created by VicChan on 2017/6/2.
//

#include "../include/Counter.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>
using std::ifstream;


int MemSteve::Counter::readFile(std::string fileName, std::string& outputString) {

    ifstream file(fileName,std::ios::binary);
    file.seekg(0, std::ios::end);
    std::ifstream::pos_type fileSize = file.tellg();
    file.seekg(0, std::ios::beg);
    char* buffer = new char[fileSize];
    file.read(buffer, fileSize);
    std::string content(buffer);
    delete [] buffer;
    outputString = content;
    return countLetters(content);

}

int MemSteve::Counter::countLetters(std::string input) {
    int sum = 0;

    for(char m: input) {
        if ((uint)m <= 255) {
            sum += 1;
            if (this->counterData[m]) {
                this->counterData[m] ++;
            } else
                this->counterData[m] = 1;
        }
    }
    return sum;
}

inline static double __calculateEntropy(double prob) {
    return -prob*log2(prob);
}

double MemSteve::Counter::calculateEntropy(std::map<char, int> s) {
    double entropy = 0.0;
    std::vector<double> probs;
    std::map<char, int>::iterator iter = s.begin();
    int sum = 0;
    double temp = 0;
    for(; iter != s.end(); iter ++) {
        temp = (double)iter->second;
        sum += temp;
        probs.push_back(temp);
    }
    for(auto i: probs) {
        entropy += __calculateEntropy(i/sum);
    }
    return entropy;
}

void MemSteve::Counter::writeLettersToFile(const std::map<char, int> &letters, const std::string fileName) {
    std::ofstream outputFile(fileName, std::ios::binary);
    std::map<char, int>::iterator iter = const_cast<std::map<char, int>& >(letters).begin();
    for(; iter != letters.end(); iter ++) {
        char s[20];
        sprintf(s,"%c,%d\n",iter->first,iter->second);
        outputFile << s;
    }
    outputFile.close();
}