//
// Created by VicChan on 2017/6/2.
//

#ifndef MEMSTEVE_COUNTER_H
#define MEMSTEVE_COUNTER_H


#include <string>
#include <map>


namespace MemSteve {

    /// Counter: Computing the frequency of each letter, punctuation and space or other characters.
    class Counter{
    public:

        /**
         * @name readFile
         * @brief read all lines from the given file
         **/
        int readFile(std::string fileName, std::string& ouputString);

        /**
         * @brief calculate the entropy of the file with the frequency of characters
         * */
        double calculateEntropy(std::map<char, int> s);

        /**
         * @return letters key-value map
         * @brief key: character value: times of apperance
         * */
        void getLetters(std::map<char, int>& letters) { letters = counterData; }

        /**
         * @brief write the letters into file
         * */
        void writeLettersToFile(const std::map<char, int>& letters, const std::string fileName);

    private:
        std::map<char, int > counterData;
        int countLetters(std::string input);


    };
}


#endif //MEMSTEVE_COUNTER_H
