#ifndef QUESTION_H
#define QUESTION_H

#include <vector>
#include <string>

class Question {
    private:
        std::string question;
        std::string correctAnswer;
        std::vector<std::string> answers;
        int topic; // 0 is math, 1 is science, 2 is music
    
    public:
        Question(std::string _question, std::string _correctAnswer, std::vector<std::string> _answers, int _topic); // Constructor
        std::string getQuestion();
        std::vector<std::string> getAnswers();
        std::string getCorrectAns();
        int getTopic();
};

#endif QUESTION_H
