//
// Created by VicChan on 2017/6/2.
//

#ifndef MEMSTEVE_WORDCOUNTER_H
#define MEMSTEVE_WORDCOUNTER_H


#include <string>
#include <vector>



namespace MemSteve {

    //
    class Letter {

    public:
        Letter(char s, int n):letter(s),count(n){};

        bool operator < (const Letter& b) const {
            return count > b.count;
        }
        int getCount() const { return count; }
        int getLetter() const { return letter; }
    private:
        int count;
        char letter;
    };

    //
    class Counter{
    public:
        /**
         * @name
         * @brief
         **/
        int readFile(std::string fileName, std::string& ouputString);

        double calculateEntropy(std::vector<Letter> s);

    private:
        Counter& operator=(Counter&);
        std::vector<Letter> counterData;
        int countLetters(std::string input);


    };
}


#endif //MEMSTEVE_WORDCOUNTER_H
