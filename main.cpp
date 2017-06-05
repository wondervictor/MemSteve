#include <iostream>
#include "include/WordCounter.h"


int main() {

    MemSteve::Counter wordCounter;

    std::string s;
    int m = wordCounter.readFile("/Users/vic/Dev/Alg/InfomationTheory/MemSteve/test/Steve.txt",s);
    std::cout<<m<<"\n";
    return 0;
}