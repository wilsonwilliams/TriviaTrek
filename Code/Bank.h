#ifndef BANK_H
#define BANK_H

#include "Question.h"
#include <vector>
#include <cstdlib>

using namespace std;

class Bank {
    private:
        std::vector<Question> easy;
        std::vector<Question> hard;
    
    public:
        Bank(); // Constructor
        Question getEasyQuestion(int topic); // gets random easy question with specified topic - 0 is math, 1 is science, 2 is music
        Question getHardQuestion(int topic); // gets random hard question with specified topic - 0 is math, 1 is science, 2 is music
};

#endif BANK_H
