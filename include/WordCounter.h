//
// Created by VicChan on 2017/6/2.
//

#ifndef MEMSTEVE_WORDCOUNTER_H
#define MEMSTEVE_WORDCOUNTER_H


#include <string>
#include <map>


namespace MemSteve {

    //
    class Counter{
    public:
        /**
         * @name
         * @brief
         **/
        int readFile(std::string fileName, std::string& ouputString);

        double calculateEntropy(std::map<char, int> s);

        void getLetters(std::map<char, int>& letters) { letters = counterData; }

    private:
        std::map<char, int > counterData;
        int countLetters(std::string input);


    };
}


#endif //MEMSTEVE_WORDCOUNTER_H
