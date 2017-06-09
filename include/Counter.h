//
// Created by VicChan on 2017/6/2.
//

#ifndef MEMSTEVE_COUNTER_H
#define MEMSTEVE_COUNTER_H


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

        void writeLettersToFile(const std::map<char, int>& letters, const std::string fileName);

    private:
        std::map<char, int > counterData;
        int countLetters(std::string input);


    };
}


#endif //MEMSTEVE_COUNTER_H
