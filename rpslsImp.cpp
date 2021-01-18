/* Matthew Kale, 5005997901, CS202 - 1005, Assignment 2
 * Description: Program that plays rock, paper, scissors, lizard, spock game
 * Input: User choice
 * Output: Game results and total round scoring
*/  

/* Algorithm
 * Set class variables to 0
 * Display choices
 * Read in user choice
 * Get cpu choice
 * Determine results
 *      Switch Statement
 * Add to wins or losses 
 */ 

#include"rpslsType.h"
#include<cstdlib>
#include<iostream>
#include<iomanip>

using namespace std;

rpslsType::rpslsType(){
    userWins = 0;
    userLosses = 0;
    gamesPlayed = 0;
}

/* playRound(): Plays the game including selection and results
 * parameters: None
 * return value: None void function
 */
void rpslsType :: playRound(){

    int user = 0;
    int cpu = 0;

    user = getUserMove();
    cpu = getComputerMove();

    switch (user){
        
        // Rock
        case 1:
            if (cpu == 2){
                cout << "Paper cover rock. Sorry, you lose." << endl;
                userLosses++;;                
            }
            if (cpu == 3){
                cout << "Rock crushes scissors. You win!" << endl;
                userWins++;
            }
            if (cpu == 4){
                cout << "Rock crushes lizard. You win!" << endl;
                userWins++;
            }
            if (cpu == 5){
                cout << "Spock vaporizes rock. Sorry, you lose." << endl;
                userLosses++;;
            }
            break;
        
        // Paper
        case 2:
            if (cpu == 1){
                cout << "Paper covers rock. You win!" << endl;
                userWins++;
            }
            if (cpu == 3){
                cout << "Scissors cut paper. Sorry, you lose." << endl;
                userLosses++;;
            }
            if (cpu == 4){
                cout << "Lizard eats paper. Sorry, you lose." << endl;
                userLosses++;;
            }
            if (cpu == 5){
                cout << "Paper disproves Spock. You win!" << endl;
                userWins++;
            }
            break;
        
        // Scissors
        case 3:
            if (cpu == 1){
                cout << "Rock crushes scissors. Sorry, you lose." << endl;
                userLosses++;;
            }
            if (cpu == 2){
                cout << "Scissors cut paper. You win!" << endl;
                userWins++;
            }
            if (cpu == 4){
                cout << "Scissors decapitate lizard. You win!" << endl;
                userWins++;
            }
            if (cpu == 5){
                cout << "Spock smashes scissors. Sorry, you lose." << endl;
                userLosses++;;
            }
            break;
        
        // Lizard
        case 4:
            if (cpu == 1){
                cout << "Rock crushes lizard. Sorry, you lose." << endl;
                userLosses++;;
            }
            if (cpu == 2){
                cout << "Lizard eats paper. You win!" << endl;
                userWins++;
            }
            if (cpu == 3){
                cout << "Scissors decapitate lizard. Sorry, you lose." << endl;
                userLosses++;;
            }
            if (cpu == 5){
                cout << "Lizard poisons Spock. You win!" << endl;
                userWins++;
            }
            break;
        
        // Spock
        case 5:
            if (cpu == 1){
                cout << "Spock vaporizes rock. You win!" << endl;
                userWins++;
            }
            if (cpu == 2){
                cout << "Paper disproves Spock. Sorry, you lose." << endl;
                userLosses++;;
            }
            if (cpu == 3){
                cout << "Spock smashes scissors. You win!" << endl;
                userWins++;
            }
            if (cpu == 4){
                cout << "Lizard poisons Spock. Sorry, you lose." << endl;
                userLosses++;;
            }
            break;
    }

    // Tie
    if (user == cpu){
            cout << "Tie!  Please try again!" << endl;
            
    }

    gamesPlayed++;
}

/* showScores(): Shows the games played, wins, and losses
 * parameters: None
 * return value: None void function
 */
void rpslsType :: showScores(){
    // Write out scores
    cout << "Score Summary" << endl;
    cout << setw(16) << right << "Games Played: " << gamesPlayed << endl;
    cout << setw(16) << right << "User wins: " << userWins << endl;
    cout << setw(16) << right << "User losses: " << userLosses << endl;
    cout << setw(16) << right << "Game Ties: " << (gamesPlayed - (userLosses+userWins)) << endl;

}

/* resetScores(): Sets the class variables back to 0
 * parameters: None
 * return value: None void function
 */
void rpslsType :: resetScores(){
    userWins = 0;
    userLosses = 0;
    gamesPlayed = 0;
}

/* playAgain(): Plays the game again if the user chooses to
 * parameters: None
 * return value: True or false
 */
bool rpslsType :: playAgain(){
    // Loop
    while (1==1){
        char choice;
        cout << endl << "Play again (Y/y/N/n) : ";
        cin >> choice;

        switch (choice)
        {
        // Play Again
        case 'Y':
        case 'y':
            return true;
            break;

        // Don't play again
        case 'N':
        case 'n':
            return false;
            break;

        default:
            cout << "Error invalid response. Please re-enter.";
            cin.clear();
            cin.ignore(100, '\n');
            break;
        }
    }
}

/* getScores(): gets the results
 * parameters: games played, wins, and losses
 * return value: None void function
 */
void rpslsType :: getScores(int &, int &, int &) const{


    // Return games played wins and losses 
}


/* playRound(): Reads in the user selection
 * parameters: None
 * return value: User moves
 */
int rpslsType :: getUserMove(){
    
    // Show options
    int selection = 0;
    cout << "------------------------------" << endl;
    cout << " Enter Move" << endl;
    cout << setw(5) << "1 " << "- Rock" << endl;
    cout << setw(5) << "2 " << "- Paper" << endl;
    cout << setw(5) << "3 " << "- Scissors" << endl;
    cout << setw(5) << "4 " << "- Lizard" << endl;
    cout << setw(5) << "5 " << "- Spock" 
        << setw(9) << right << ": ";

    // Read in 
    cin >> selection;

    // Fail state
    while (cin.fail() || selection > 5 || selection < 1){
    
        cout << "Error invalid input." << endl;
        cin.clear();
        cin.ignore(100, '\n');

        cout << "------------------------------" << endl;
        cout << " Enter Move" << endl;
        cout << setw(5) << "1 " << "- Rock" << endl;
        cout << setw(5) << "2 " << "- Paper" << endl;
        cout << setw(5) << "3 " << "- Scissors" << endl;
        cout << setw(5) << "4 " << "- Lizard" << endl;
        cout << setw(5) << "5 " << "- Spock" 
            << setw(9) << right << ": ";

        cin >> selection;

    }
    
    cout << endl; 
    return selection;
}

/* getComputerMove(): Gets the computer selection
 * parameters: None
 * return value: computer choice
 */
int rpslsType :: getComputerMove(){

    // Get computer choice
    int CpuMove;
    CpuMove = (rand() % 5 + 1);
    return CpuMove;

}
