#include <iostream>

using namespace std;

string getWord(string letter) {
    string returnedWord;
    if (letter == "r") {
        returnedWord = "rock";
    } else if (letter == "p") {
        returnedWord = "paper";
    } else {
        returnedWord = "scissors";
    }
    return returnedWord;
}

int main() {
    cout << "-- WELCOME TO ROCK PAPER SCISSORS --" << endl;
    bool keepPlaying = true;
    int userScore = 0;
    int computerScore = 0;
    int round = 1;

    while (keepPlaying) {
        string userInput;
        string computerInput;
        string winner;
        string pagain;
        srand(time(0));

        cout << "Round " << round << ":"<< endl;
        cout << "Make your choice: Rock(r), Paper(p) or Scissors(s):";
        cin >> userInput;
        //cout << userInput << endl; // TEMP
        if (userInput == "r" or userInput == "p" or userInput == "s") {
            // COMPUTER RESPONSE
            int randNum = rand() % 3 + 1; // Get a random number and get the remainder either being 0, 1, or 2, then add 1 to it
            switch (randNum) {
                case 1:
                    computerInput = "r";
                    break;
                case 2:
                    computerInput = "p";
                    break;
                case 3:
                    computerInput = "s";
                    break;
                default:
                    cout << "Something sus happened!" << endl;
            }
            //cout << randNum << endl; // TEMP
            //cout << computerInput << endl; // TEMP
        } else {
            cout << "ENTER A VALID INPUT BOZO" << endl;
            continue;
        }

        // WIN PROCESSING
        if (userInput == "r") {
            if (computerInput == "p") {
                winner = "computer";
                computerScore++;
            } else if (computerInput == "s") {
                winner = "player";
                userScore++;
            }
        }
        else if (userInput == "p") {
            if (computerInput == "s") {
                winner = "computer";
                computerScore++;
            } else if (computerInput == "r") {
                winner = "player";
                userScore++;
            }
        }
        else if (userInput == "s") {
            if (computerInput == "r") {
                winner = "computer";
                computerScore++;
            } else if (computerInput == "p") {
                winner = "player";
                userScore++;
            }
        } else {
            winner = "tie";
        }

        // PRINT RESULTS
        if (winner == "player") {
            cout << "You entered " << getWord(userInput) << " and the computer chose " << getWord(computerInput) << ". You Won :D\n";
        } else if (winner == "computer") {
            cout << "You entered " << getWord(userInput) << " and the computer chose " << getWord(computerInput) << ". You Lost, BOZO\n";
        } else {
            cout << "You both entered " << getWord(userInput) << ". It's a tie :/\n";
        }
        cout << "-- SCORE -- \nPlayer: " << userScore << "  Computer: " << computerScore << endl;
        if (userScore > computerScore) {
            cout << "Good job beating the computer by " << userScore - computerScore << ".";
        } else if (userScore < computerScore) {
            cout << "YOOOOOOO you gotta catch up the the computer. It's beating you by " << computerScore - userScore << ".";
        } else {
            cout << "You and the computer both have " << userScore << " points. Get this next one to take the lead.";
        }
        cout << endl;

        // ASK TO PLAY AGAIN
        cout << "Do you want to play again? (y for yes, n for no): ";
        cin >> pagain;
        if (pagain == "y" || pagain == "yes") {
            keepPlaying = true;
        } else if (pagain == "n" || pagain == "no") {
            keepPlaying = false;
        } else {
            cout << "You didn't follow the instructions, but you can play again.\n";
            continue;
        }
        round++;
        cout << endl; // space out each round of rock paper scissors
    }
    // GAME ENDING
    if (round > 2) { // will be 2 after 1 game because it starts at 1 and is incremented at the end of loop
        cout << "Thanks for playing " << round - 1 << " games of Rock Paper Scissors :)\n"; // -1 because it increments in loop
    } else {
        cout << "Thanks for playing a game of Rock Paper Scissors :)\n";
    }
    cout << "-- PROGRAM ENDING -- ";
    return 0;
}
