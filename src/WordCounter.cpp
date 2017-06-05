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

    std::map<char, int> letters;

    for(char m: input) {
        if (letters[m]) {
            letters[m] ++;
        } else
            letters[m] = 1;
    }
    int sum = 0;
    for (std::map<char, int>::iterator p = letters.begin(); p != letters.end(); p ++) {
        if ((uint)p->first <= 255) {
            Letter letter(p->first,p->second);
            this->counterData.push_back(letter);
            sum += p->second;
        }
    }
    return sum;
}

double MemSteve::Counter::calculateEntropy(std::vector<Letter> s) {
    double entropy = 0.0;

    return entropy;
}
