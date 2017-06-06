//
// Created by VicChan on 2017/6/2.
//

#include "../include/WordCounter.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
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

double MemSteve::Counter::calculateEntropy(std::map<char, int> s) {
    double entropy = 0.0;

    return entropy;
}
