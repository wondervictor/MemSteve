#include <iostream>
#include "include/WordCounter.h"
#include "include/Encoding.h"



int main() {

    MemSteve::Counter wordCounter;

    std::string s;
    int m = wordCounter.readFile("/Users/vic/Dev/Alg/InfomationTheory/MemSteve/test/Steve.txt",s);
    std::vector<MemSteve::Letter> letters;
    wordCounter.getLetters(letters);
    MemSteve::HuffmenTree ht(letters);
    std::cout<<m<<"\n";
    std::map<char, std::string> code;
    ht.encode(code);
//    std::map<char, std::string>::iterator iter;
//    for( iter = code.begin(); iter != code.end(); iter++) {
//        std::cout<<iter->first<<":"<<iter->second<<"\n";
//    }

    return 0;
}