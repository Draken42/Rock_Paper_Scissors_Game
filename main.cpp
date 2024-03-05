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
    cout << "\t-- WELCOME TO ROCK PAPER SCISSORS --" << endl;
    bool keepPlaying = true;
    bool computerOpponent;
    bool playerOne;
    int round = 1;
    int userScore = 0;
    int computerScore = 0;
    int player1Score = 0;
    int player2Score = 0;
    string answer;

    // CHOOSE OPPONENT
    cout << "Would you like to play against the computer? y for yes, n for no:";
    cin >> answer;
    if (answer == "y" || answer == "yes") {
        computerOpponent = true;
    } else if (answer == "n" || answer == "no") {
        computerOpponent = false;
        playerOne = true;
    } else {
        cout << "You didn't follow directions so you get to play against the computer and probably lose.\n";
        computerOpponent = true;
    }

    while (keepPlaying) {
        string winner;
        string pagain;
        srand(time(0));

        cout << "Round " << round << ":"<< endl;
        if (computerOpponent) {
            string userInput;
            string computerInput;
            cout << "Make your choice: Rock(r), Paper(p) or Scissors(s):";
            cin >> userInput;

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
            } else if (userInput == "p") {
                if (computerInput == "s") {
                    winner = "computer";
                    computerScore++;
                } else if (computerInput == "r") {
                    winner = "player";
                    userScore++;
                }
            } else if (userInput == "s") {
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
                cout << "You entered " << getWord(userInput) << " and the computer chose " << getWord(computerInput)
                     << ". You Won :D\n";
            } else if (winner == "computer") {
                cout << "You entered " << getWord(userInput) << " and the computer chose " << getWord(computerInput)
                     << ". You Lost, BOZO\n";
            } else {
                cout << "You both entered " << getWord(userInput) << ". It's a tie :/\n";
            }
            cout << "-- SCORE -- \nPlayer: " << userScore << "  Computer: " << computerScore << endl;
            if (userScore > computerScore) {
                cout << "Good job beating the computer by " << userScore - computerScore << ".";
            } else if (userScore < computerScore) {
                cout << "YOOOOOOOO you gotta catch up the the computer. It's beating you by " << computerScore - userScore
                     << ".";
            } else {
                cout << "You and the computer both have " << userScore << " points. Get this next one to take the lead.";
            }
            cout << endl;

        } else { // human opponent
            string player1Input;
            string player2Input;
            cout << "Player 1, make your choice: Rock(r), Paper(p) or Scissors(s): (PLAYER 2, LOOK AWAY!)";
            cin >> player1Input;
            cout << "\n\n\n\n\n\n\n\n\n\n\n";
            cout << "Player 2, make your choice: Rock(r), Paper(p) or Scissors(s):";
            cin >> player2Input;

            // Check valid input
            if (player1Input == "r" or player1Input == "p" or player1Input == "s") {
                if (player2Input == "r" or player2Input == "p" or player2Input == "s") {
                    // WIN PROCESSING
                    if (player1Input == "r") {
                        if (player2Input == "p") {
                            winner = "player2";
                            player2Score++;
                        } else if (player2Input == "s") {
                            winner = "player1";
                            player1Score++;
                        } else if (player2Input == "r") {
                            winner = "tie";
                        } else {
                            cout << "ENTER A VALID INPUT >:C\n";
                            continue;
                        }
                    } else if (player1Input == "p") {
                        if (player2Input == "s") {
                            winner = "player2";
                            player2Score++;
                        } else if (player2Input == "r") {
                            winner = "player1";
                            player1Score++;
                        } else if (player2Input == "p") {
                            winner = "tie";
                        } else {
                            cout << "ENTER A VALID INPUT >:C\n";
                            continue;
                        }
                    } else if (player1Input == "s") {
                        if (player2Input == "r") {
                            winner = "player2";
                            player2Score++;
                        } else if (player2Input == "p") {
                            winner = "player1";
                            player1Score++;
                        } else if (player2Input == "s") {
                            winner = "tie";
                        } else {
                            cout << "ENTER A VALID INPUT >:C\n";
                            continue;
                        }
                    } else {
                        cout << "ENTER A VALID INPUT >:C\n";
                        continue;
                    }

                    // PRINT RESULTS
                    if (winner == "player1") {
                        cout << "Player1 entered " << getWord(player1Input) << " and Player2 entered "
                             << getWord(player2Input) << ". Player1 wins :D and Player2 is a BOZO!\n";
                    } else if (winner == "player2") {
                        cout << "Player1 entered " << getWord(player1Input) << " and Player2 entered "
                             << getWord(player2Input) << ". Player2 wins :D and Player1 is a BOZO!\n";
                    } else {
                        cout << "You both entered " << getWord(player1Input) << ". It's a tie :/\n";
                    }
                    //PRINT SCORE
                    cout << "-- SCORE -- \nPlayer1: " << player1Score << "  Player2: " << player2Score << endl;
                    if (player1Score > player2Score) {
                        cout << "Player1 is beating Player2 by " << player1Score - player2Score
                             << ". Get better Player2!\n";
                    } else if (player1Score < player2Score) {
                        cout << "Player2 is beating Player1 by " << player2Score - player1Score
                             << ". Get better Player1!\n";
                    } else {
                        printf("You both have %d points. Someone gotta score next time\n", player1Score);
                    }
                    cout << endl;
                } else {
                    cout << "BOZO PLAYER2 ENTER A VALID INPUT >:C\n";
                    continue;
                }
            } else {
                cout << "BOZO PLAYER2 ENTER A VALID INPUT >:C\n";
                continue;
            }
        }


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
    cout << "\t-- PROGRAM ENDING -- ";
    return 0;
}
