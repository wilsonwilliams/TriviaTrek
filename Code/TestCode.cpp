#include <iostream>
#include "Bank.h"
#include "Game.h"

#include <windows.h> // remove this - used for Sleep(ms)

using namespace std;

void getEasyRandomQuestions(Bank bank, int topic, int n) {
    // Get n random easy [topic] questions and print out the question, answer choices, and correct answer
    for (int i = 0; i < n; ++i) {
        Question q = bank.getEasyQuestion(topic);
        std::cout << "Question is: " << q.getQuestion() << std::endl;
        std::cout << "The answer choices are... " << std::endl;
        for (std::string s : q.getAnswers()) {
            std::cout << s << std::endl;
        }
        std::cout << "The correct answer choice is: " << q.getCorrectAns() << std::endl << std::endl;
        Sleep(1000);
    }
}

void getHardRandomQuestions(Bank bank, int topic, int n) {
    // Get n random hard [topic] questions and print out the question, answer choices, and correct answer
    for (int i = 0; i < n; ++i) {
        Question q = bank.getHardQuestion(topic);
        std::cout << "Question is: " << q.getQuestion() << std::endl;
        std::cout << "The answer choices are... " << std::endl;
        for (std::string s : q.getAnswers()) {
            std::cout << s << std::endl;
        }
        std::cout << "The correct answer choice is: " << q.getCorrectAns() << std::endl << std::endl;
        Sleep(1000);
    }
}

int main() {
    // // Initialize question bank
    // Bank bank;

    // getEasyRandomQuestions(bank, 0, 3); // get 3 easy math questions
    // getEasyRandomQuestions(bank, 1, 3); // get 3 easy science questions
    // getEasyRandomQuestions(bank, 2, 3); // get 3 easy music questions

    // getHardRandomQuestions(bank, 0, 3); // get 3 hard math questions
    // getHardRandomQuestions(bank, 1, 3); // get 3 hard science questions
    // getHardRandomQuestions(bank, 2, 3); // get 3 hard music questions

    // Initialize game
    // Game game;

    // cout << "Player 1 position: " << game.getCurrPlayerPos() << endl;
    // game.setCurrPlayerPos(1);
    // cout << "Player 1 new position: " << game.getCurrPlayerPos() << endl << endl;

    // game.nextPlayer();

    // cout << "Player 2 position: " << game.getCurrPlayerPos() << endl;
    // game.setCurrPlayerPos(2);
    // cout << "Player 2 new position: " << game.getCurrPlayerPos() << endl << endl;

    // game.nextPlayer();

    // cout << "Player 3 position: " << game.getCurrPlayerPos() << endl;
    // game.setCurrPlayerPos(40);
    // cout << "Player 3 new position: " << game.getCurrPlayerPos() << endl << endl;

    // cout << "Has player 3 won?   " << game.checkWinner() << endl << endl;

    // game.nextPlayer();

    // cout << "Player 1 position: " << game.getCurrPlayerPos() << endl;
    // game.setCurrPlayerPos(4);
    // cout << "Player 1 new position: " << game.getCurrPlayerPos() << endl << endl;

    // Check if current position is a slide or ladder and return next position
    // cout << "Position 1 -> Position " << game.checkSlide(1) << endl;
    // cout << "Position 2 -> Position " << game.checkSlide(2) << endl;
    // cout << "Position 7 -> Position " << game.checkSlide(7) << endl;
    // cout << "Position 10 -> Position " << game.checkSlide(10) << endl;
    // cout << "Position 28 -> Position " << game.checkSlide(28) << endl;
}
