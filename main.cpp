#include <iostream>
#include "include/Counter.h"
#include "include/Encoding.h"
#include "include/Common.h"


void huffmen(std::map<char, int>& letters, std::string& inputString, std::string& path) {
    std::map<char, std::string> code;
    std::string outputString;
    timeInterval time;
    startTimer();
    float l = MemSteve::codeByHuffmen(letters,inputString,outputString,code,path+"huffmen.dat",path+"huffmencode.csv");
    stopTimer(time);

    std::string decodeString;
    MemSteve::decode(outputString,code,decodeString,path+"huffmendecode.txt");
    // uncomment the below line output the encoded string to the terminal
    //std::cout<<"output:"<<outputString<<std::end;
    std::cout<<"Huffmen Encoding Finished!"<<"\n";
    std::cout<<"Huffmen Encoding Code Length: "<<l<<"\n";
    std::cout<<"Huffmen Encoding Time Duration: "<<time<<"\n\n";

}

void shannon(std::map<char, int>& letters, std::string& inputString, std::string& path) {
    std::map<char, std::string> code;
    std::string outputString;
    timeInterval time;
    startTimer();
    float l = MemSteve::codeByShannon(letters,inputString,outputString,code,path+"shanon.dat",path+"shannoncode.csv");
    stopTimer(time);
    std::string decodeString;
    MemSteve::decode(outputString,code,decodeString,path+"Shannondecode.txt");
    // uncomment the below line output the encoded string to the terminal
    //std::cout<<"output:"<<outputString<<std::end;
    std::cout<<"Shannon Encoding Finished!"<<"\n";
    std::cout<<"Shannon Encoding Code Length: "<<l<<"\n";
    std::cout<<"Shannon Encoding Time Duration: "<<time<<"\n\n";
}

void shannonFanoElias(std::map<char, int>& letters, std::string& inputString, std::string& path) {
    std::map<char, std::string> code;
    std::string outputString;
    timeInterval time;
    startTimer();
    float l = MemSteve::codeByShannonFanoElias(letters,inputString,outputString,code,path+"shanon_fano_elias.dat",path+"sfecode.csv");
    stopTimer(time);
    std::string decodeString;
    MemSteve::decode(outputString,code,decodeString,path+"sfedecode.txt");
    // uncomment the below line output the encoded string to the terminal
    //std::cout<<"output:"<<outputString<<std::end;
    std::cout<<"Shannon-Fano-Elias Encoding Finished!"<<"\n";
    std::cout<<"Shannon-Fano-Elias Encoding Code Length: "<<l<<"\n";
    std::cout<<"Shannon-Fano-Elias Encoding Time Duration: "<<time<<"\n\n";
}


int main() {

    std::cout<<"Initializing ...." <<std::endl;
    // Counter Instance
    MemSteve::Counter wordCounter;
    // txt file string
    std::string s;
#warning please change the path when you run in your own computer
    std::string path = "/Users/vic/Dev/Alg/InfomationTheory/MemSteve/test/";
    int m = wordCounter.readFile(path+"Steve.txt",s);
    std::map<char, int> letters;
    wordCounter.getLetters(letters);
    wordCounter.writeLettersToFile(letters,path+"letter.csv");
    double entropy = wordCounter.calculateEntropy(letters);
    std::cout<<"Initialized Data Finished!"<<"\n";
    std::cout<<"Passage Entropy: "<<entropy<<"\n";
    std::cout<<"Passage Char Number: "<<m<<"\n\n";


    shannon(letters,s,path);
    huffmen(letters,s,path);
    shannonFanoElias(letters,s,path);
    return 0;
}