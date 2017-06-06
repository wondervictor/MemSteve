#include <iostream>
#include "include/Counter.h"
#include "include/Encoding.h"



int main() {

    MemSteve::Counter wordCounter;

    std::string s;
    std::string path = "/Users/vic/Dev/Alg/InfomationTheory/MemSteve/test/";
    int m = wordCounter.readFile(path+"Steve.txt",s);
    std::map<char, int> letters;
    wordCounter.getLetters(letters);

    float l = MemSteve::codeByShannon(letters,s,path+"shannon.dat");//MemSteve::codeByHuffmen(letters,s,path+"huffmen.dat");
    std::cout<<"\n"<<"code length: "<<l<<"\n";

//    MemSteve::HuffmenTree ht(letters);
//    std::cout<<m<<"\n";
//    std::map<char, std::string> code;
//    ht.encode(code);
//    std::map<char, std::string>::iterator iter;
//    for( iter = code.begin(); iter != code.end(); iter++) {
//        std::cout<<iter->first<<":"<<iter->second<<"\n";
//    }

    return 0;
}