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
    ht.traverseTree();
    std::cout<<m<<"\n";
    return 0;
}