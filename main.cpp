#include <iostream>
#include "include/Counter.h"
#include "include/Encoding.h"



int main() {

    MemSteve::Counter wordCounter;

    std::string s;
    std::string path = "/Users/vic/Dev/Alg/InfomationTheory/MemSteve/test/";
    int m = wordCounter.readFile(path+"Steve.txt",s);
    std::map<char, int> letters;
    std::map<char, std::string> code;
    wordCounter.getLetters(letters);
    wordCounter.writeLettersToFile(letters,path+"letter.csv");
    double entropy = wordCounter.calculateEntropy(letters);
    std::cout<<"Entropy: "<<entropy<<"\n";
    std::string outputString;
    float l = MemSteve::codeByShannon(letters,s,outputString,code,path+"shannon.dat",path+"shannoncode.txt");//MemSteve::codeByHuffmen(letters,s,path+"huffmen.dat");
    std::cout<<"\n"<<"code length: "<<l<<"\n";
    std::string decodeString;
    MemSteve::decode(outputString,code,decodeString);

    std::cout<<decodeString<<"\n";


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