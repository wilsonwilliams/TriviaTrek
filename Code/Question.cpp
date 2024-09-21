#include "Question.h"

// Constructor
Question::Question(std::string _question, std::string _correctAnswer, std::vector<std::string> _answers, int _topic) {
    question = _question;
    correctAnswer = _correctAnswer;
    topic = _topic;
    
    answers.push_back(_correctAnswer);
    for (std::string a : _answers) {
        answers.push_back(a);
    }
}

// Get the question
std::string Question::getQuestion() {
    return question;
}

// Get a vector of all answer choices
// TODO: Randomize the order of the vector
std::vector<std::string> Question::getAnswers() {
    return answers;
}

// Get the correct answer
std::string Question::getCorrectAns() {
    return correctAnswer;
}

// Get the topic
// 0 is math, 1 is science, 2 is music
int Question::getTopic() {
    return topic;
}
