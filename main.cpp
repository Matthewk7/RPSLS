//  CS 202
//  Provided Main Program
//  Assignment #2 - Rock-Paper-Scissors-Lizard-Spock

//  C++ main program to Rock-Paper-Scissors-Lizard-Spock object.

// ***********************************************************************
//  Includes and prototypes.
  
#include <iostream>
#include <string>
#include "rpslsType.h"

using namespace std;

// ***********************************************************************

int main()
{
	// ------------------------------
	//  Declarations and headers.

	string	stars, bars;
	stars.append(60,'*');
	bars.append(50,'=');

	cout << stars << endl;
	cout << "CS 202 - Assignment #2" << endl;
	cout << "Rock Paper Scissors Lizard Spock Game" << endl;
	cout << endl << endl;

	// ------------------------------
	//  Play the game.

	rpslsType	game1;

	cout << bars << endl << "Stage 1 - Best of 5 games" << endl << endl;

	for (int i=0; i<5; i++) {
		game1.playRound();
	}
	game1.showScores();

	// ------------------------------
	//  Play the game.

	rpslsType	game2;
	bool	keepPlaying = true;
	int	gameCount=0;

	cout << bars << endl << "Stage 2 - Unlimited" << endl << endl;

	while (keepPlaying) {
		game2.playRound();
		gameCount++;
		keepPlaying = game2.playAgain();
	}
	game2.showScores();

	// ------------------------------
	//  Misc. sanity checks...

	rpslsType	game3(game2);
	int	games2, wins2, losses2;
	int	games3, wins3, losses3;

	game2.getScores(games2, wins2, losses2);

	if (gameCount != games2)
		cout << "Error 1, invalid results." << endl;

	if (games2 < (wins2+losses2))
		cout << "Error 2, invalid results." << endl;


	// ------------------------------
	//  Show default compy constructor.

	game3.getScores(games3, wins3, losses3);

	if (games2 != games3 || wins2 != wins3 || losses2 != losses3)
		cout << "Error 3, invalid results." << endl;

	// ------------------------------
	//  Play the game.

	cout << bars << endl << "Stage 3 - One game, All-or-Nothing" << endl << endl;

	game2.resetScores();
	game2.playRound();
	game2.showScores();

	// ------------------------------
	//  All done.

	cout << bars << endl;
	cout << "Program Terminated." << endl << endl;

	return 0;
}


