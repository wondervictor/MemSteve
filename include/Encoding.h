//
// Created by VicChan on 2017/6/2.
//

#ifndef MEMSTEVE_ENCODING_H
#define MEMSTEVE_ENCODING_H

#include <map>
#include "WordCounter.h"

namespace MemSteve {

    class Encoder {

    public:

        Encoder();

        Encoder(std::map<char, std::string>& c):code(c){};

        int encode(const std::string& inputString,
                   const std::map<char, std::string>& c,
                   std::string& outputString);

        int encode(const std::string& inputString, std::string& outputString);

    private:
        std::map<char, std::string> code;


    };

    float codeByHuffmen(const std::vector<Letter>& letters,
                       std::map<char, std::string> code,
                       std::string outputFileName);

    float codeByShannon(const std::vector<Letter>& letters,
                       std::map<char, std::string> code,
                       std::string outputFileName);

}




#endif //MEMSTEVE_ENCODING_H
