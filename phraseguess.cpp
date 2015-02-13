/***********************************************************
* Author:                             Kyle Wood
* Date Created:                       1/29/14
* Last Modification Date:             2/2/14
* Filename:                           phraseguess.cpp
*
* Overview:
*	This program will create a random 3 word phrase by picking
*	3 words from a pre-filled array. The player will then
*	guess the phrase word by word by guessing letters. They
*	will have a total of 8 guesses per word and will lose if
*	if they fail to guess any of the words in that limit. The
*	program also allows multiple replays without restarting
*	the program.
*
************************************************************/
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	char game;
	game = 'Y';
	const char Y = 'Y';
	const char N = 'N';
	int randomizer = 1; //Used to help change the srand every time the player decides to replay the game without closing the program
	while ((game == 'Y') || (game == 'y')) //Master loop used for the replay function
	{
		cout << "Welcome Player 1! Today you will be guessing a 3 word phrase word by word." << endl << endl;
		int words = 3;
		int victory = 0;
		string phrasewords[] = { "duck", "when", "were", "face", "door", "case", "huff", "blow", "back", "lisp", "felt", "pond" };
		string phrase, phrasecopy, word1, word2, word3;
		srand(time(NULL) + randomizer); //A function I found online to make the srand change every time the program is run
		while (words > 0)
		{
			word1 = phrasewords[rand() % 12];	 //Random number used to guess each of the words for each part of the phrase
			randomizer = randomizer + 1;         //Used to change the srand, if not it would keep picking the same word
			word2 = phrasewords[rand() % 12];
			randomizer = randomizer + 1;
			word3 = phrasewords[rand() % 12];
			randomizer = randomizer + 1;
			if (words == 3)
			{
				phrase = word1;
				cout << "Player 1 it is time to guess the FIRST word of the 3 word phrase." << endl;
			}
			if (words == 2)
			{
				phrase = word2;
				cout << "Player 1 it is time to guess the SECOND word of the 3 word phrase." << endl;
			}
			if (words == 1)
			{
				victory = 1;
				phrase = word3;
				cout << "Player 1 it is time to guess the THIRD AND FINAL word of the 3 word phrase." << endl;
			}
			phrasecopy = phrase;
			char x, guess1, guess2, guess3, guess4, guess5, guess6, guess7, guess8;
			x = '_';
			guess1 = x;
			guess2 = x;
			guess3 = x;
			guess4 = x;
			guess5 = x;
			guess6 = x;
			guess7 = x;
			guess8 = x;
			int failstate;
			failstate = 0;
			phrasecopy[0] = x;
			phrasecopy[1] = x;
			phrasecopy[2] = x;
			phrasecopy[3] = x;
			int guesses;
			guesses = 8;

			while (guesses > 0)
			{
				char guess, a, b, c, d; //Variables to store the letters of 'phrase' for easy use later
				a = phrase[0];
				b = phrase[1];
				c = phrase[2];
				d = phrase[3];
				cout << "Player 1 please guess a letter (lowercase only)." << endl << "Here is what you have gotten so far:" << endl << phrasecopy[0] << " " << phrasecopy[1] << " " << phrasecopy[2] << " " << phrasecopy[3] << endl << "You have " << guesses << " tries left." << endl << "Here are the letters you have guessed so far:" << endl << guess1 << " " << guess2 << " " << guess3 << " " << guess4 << " " << guess5 << " " << guess6 << " " << guess7 << " " << guess8 << endl;
				std::cin >> guess;

				if (isalpha(guess)) //Function to make sure the user input is a letter
				{
					cout << endl;
				}
				else
				{
					cout << "ERROR. Please enter a valid lowercase letter." << endl << endl;
					continue;
				}
				if (isupper(guess)) //Function to make sure the user enters a lowercase letter
				{
					cout << "ERROR. Please enter a valid lowercase letter." << endl << endl;
					continue;
				}
				if ((guess == guess1) || (guess == guess2) || (guess == guess3) || (guess == guess4) || (guess == guess5) || (guess == guess6) || (guess == guess7) || (guess == guess7)) //Used to avoid repeating previous guesses and losing turns because of it
				{
					cout << "ERROR. You already guessed that letter." << endl << endl;
					continue;
				}
				if (guess == a)
				{
					phrasecopy[0] = phrase[0];
					cout << "Congrats! You guessed a correct letter!" << endl << endl;
				}
				if (guess == b)
				{
					phrasecopy[1] = phrase[1];
					cout << "Congrats! You guessed a correct letter!" << endl << endl;
				}
				if (guess == c)
				{
					phrasecopy[2] = phrase[2];
					cout << "Congrats! You guessed a correct letter!" << endl << endl;
				}
				if (guess == d)
				{
					phrasecopy[3] = phrase[3];
					cout << "Congrats! You guessed a correct letter!" << endl << endl;
				}
				if ((guess != a) && (guess != b) && (guess != c) && (guess != d))
				{
					cout << "Sorry, that was not one of the letters." << endl << endl;
				}
				if ((phrasecopy[0] == phrase[0]) && (phrasecopy[1] == phrase[1]) && (phrasecopy[2] == phrase[2]) && (phrasecopy[3] == phrase[3])) //Victory condition for a word (not the whole phrase though)
				{
					cout << "Awesome! You got it! You guessed the word:" << endl << phrasecopy << endl << endl;
					words = words - 1;
					break;
				}
				if (guesses == 8) //Used to store the player's guesses so the program can check and make sure they don't repeat previous guesses
				{
					guess1 = guess;
				}
				if (guesses == 7)
				{
					guess2 = guess;
				}
				if (guesses == 6)
				{
					guess3 = guess;
				}
				if (guesses == 5)
				{
					guess4 = guess;
				}
				if (guesses == 4)
				{
					guess5 = guess;
				}
				if (guesses == 3)
				{
					guess6 = guess;
				}
				if (guesses == 2)
				{
					guess7 = guess;
				}
				if (guesses == 1)
				{
					guess8 = guess;
				}
				if (guesses > 0)
				{
					guesses = guesses - 1;
				}
				if (guesses == 0)
				{
					cout << "Sorry, but you did not guess the word in time. You lose!" << endl << endl;
					failstate = failstate + 1; //Used to initiate failure sequence below
				}
			}
			if ((victory == 1) && (phrasecopy == word3))
			{
				cout << "CONGRATULATIONS!!! You guessed the 3 word phrase " << "'" << word1 << " " << word2 << " " << word3 << "'! YOU WIN!!!" << endl << endl; //Victory condition for the whole phrase
				break;
			}
			while (failstate >= 1) //Failure sequence
			{
				if (phrasecopy[0] != phrase[0])
				{
					cout << "Player 1, you missed the letter '" << phrase[0] << "'" << endl;
				}
				if (phrasecopy[1] != phrase[1])
				{
					cout << "Player 1, you missed the letter '" << phrase[1] << "'" << endl;
				}
				if (phrasecopy[2] != phrase[2])
				{
					cout << "Player 1, you missed the letter '" << phrase[2] << "'" << endl;
				}
				if (phrasecopy[3] != phrase[3])
				{
					cout << "Player 1, you missed the letter '" << phrase[3] << "'" << endl;
				}
				if (failstate = 1)
				{
					cout << endl << "The correct word was:" << endl << phrase << endl << endl;
					failstate = failstate - 1;
				}
				cout << "Too Bad! You failed to guess the 3 word phrase '" << word1 << " " << word2 << " " << word3 << "' YOU LOSE!!!" << endl << endl;
 				words = 0;
			}
		}
		randomizer = randomizer + 1; //added to change the srand if the player decides to play again
		cout << "Would you like to play again Y/N?" << endl;
		std::cin >> game;
	}


	if ((game == 'N') || (game == 'n')) //Ends the main loop if player does not wish to play again
	{
		cout << "Thanks for playing!";
	}

	std::cin.get();
	std::cin.get(); // I added these two to make the executable pause before closing when I compile at home

	return 0;
}