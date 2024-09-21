// example main file
// copy to an arduino .ino file

#include "Bank.h"
#include "Button.h"
#include "Display.h"
#include "DistanceSensor.h"
#include "Game.h"
#include "LED.h"
#include "Player.h"
#include "Question.h"
#include "Servo.h"
#include "Speaker.h"

#include <StandardCplusplus.h>

// Initialize everything
Bank bank;
// Game game;
Button redButton(6);
Button yellowButton(5);
Button greenButton(4);
Button blueButton(3);

void setup() {

}

void loop() {
    // Initialize things
    Display lcd;
    Game game;

    lcd.displayStart(); // welcome screen
    int gameDifficulty = game.getGameDifficulty(); // 0 is easy, 1 is hard

    while (1) {
        // get current player's position
        int currPos = game.getCurrPlayerPos();

        // display current player's turn
        lcd.displayCurrPlayer(game.getCurrPlayerNumber());

        // wait until player is ready (blue button pushed)
        while (!blueButton.readButton()) {}
        lcd.displayGettingQ();

        // get topic of current square
        int topic;
        if (currPos % 3 == 1) {
            // math square
            topic = 0;
        } else if (currPos % 3 == 2) {
            // music square
            topic = 2;
        } else {
            // science square
            topic = 1;
        }

        // get question, correct answer, and answers vector
        std::string question;
        std::string correctAns;
        std::vector<std::string> answers;
        if (!gameDifficulty) {
            // get easy question
            Question q = bank.getEasyQuestion(topic);
            question = q.getQuestion();
            correctAns = q.getCorrectAns();
            answers = q.getAnswers();
        } else {
            // get hard question
            Question q = bank.getHardQuestion(topic);
            question = q.getQuestion();
            correctAns = q.getCorrectAns();
            answers = q.getAnswers();
        }

        // display full question
        lcd.displayFullQuestion(question);

        // display question and answer choices
        
        // get user answer
        std::string selectedAns = answers[0];
        while (1) {
            if (redButton.readButton()) {
                // current answer is selected
                delay(500);
                break;
            } else if (yellowButton.readButton()) {
                // go to previous answer
                delay(500);
            } else if (greenButton.readButton()) {
                // go to next answer
                delay(500);
            }
        }

        // check if user answer is correct
        if (selectedAns == correctAns) {
            // notify player if answer was correct

            // spin motor
            int diceRoll = game.rollDice(); // get random number 1-6

            // update user position (check if new position is a slide or ladder)
            game.setCurrPlayerPos(game.checkSlide(game.getCurrPlayerPos() + diceRoll));

            // check if user won and break loop if someone won
            if (game.checkWinner()) {
                break;
            }
        
            // tell player which spot to move to

        }

        // update current player
        game.nextPlayer();
    }
    
    // put code here for when a player wins
    
}
