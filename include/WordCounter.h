//
// Created by VicChan on 2017/6/2.
//

#ifndef MEMSTEVE_WORDCOUNTER_H
#define MEMSTEVE_WORDCOUNTER_H


#include <string>
#include <vector>



namespace MemSteve {

    //
    struct Letter {
        int count;
        char letter;
        Letter(char s, int n):letter(s),count(n){};
        inline bool operator > (const Letter& a, const Letter& b) {
            return a.count > b.count;
        }
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
