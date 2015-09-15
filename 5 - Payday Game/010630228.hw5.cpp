//Tara Moses
//March 17, 2015
//Homework 5: Pay Day

#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;

const int ROWS = 4;
const int COLS = 6;

//welcome the user i guess
void welcomeMessage() {
	cout << "Hello! You're going to play PAYDAY." << endl;
	cout << "INSTRUCTIONS: you roll a die and move that many spaces. Ezpz." << endl;
	cout << "First person to the end of the board wins!" << endl;
}

//initialize the board randomly! make it rain bonus points ezpz
void initBoard(char board[ROWS][COLS]) {
	char chars[] = {'A','E','I','O','U'};
	int randomNum;
	
	for (int r=0;r<ROWS;r++) {
		for (int c=0;c<COLS;c++) {
			randomNum = rand() % 5;
			board[r][c] = chars[randomNum];
		}
	}
}

//who's the winner??
void displayWinner(int p1money, int p2money) {
	if (p1money>p2money) cout << "PLAYER 1, YOU WON!! WITH $" << p1money << "!\n";
	else if (p2money>p1money) cout << "PLAYER 2, YOU WON!! WITH $" << p2money << "!\n";
	else cout << "TIE! BOTH PLAYERS ENDED THE GAME WITH " << p1money << "!\n";
}

bool gameOver(int p1row, int p2row) {
	if (p1row>3) return true;
	else if (p2row>3) return true;
	return false;
}

// Rolls the dice (1 - 6)
int diceRoll()
{
    int roll = 0;
    roll = (rand() % 6) + 1;
    
    return roll;
}

// Prints the board
void printBoard(const char board[ROWS][COLS], 
                const int playerOneRow, const int playerOneCol, 
                const int playerTwoRow, const int playerTwoCol)
{
    cout << "\n+---+---+---+---+---+---+\n";
    for (int r = 0; r < ROWS; r++)
    {
        cout << "| ";
        for (int c = 0; c < COLS; c++)
        {
            if (c==playerOneCol && r==playerOneRow) cout << "1";
            else if (c==playerTwoCol && r==playerTwoRow) cout << "2";
            else cout << board[r][c];
            cout << " | ";
        }
        cout << "\n+---+---+---+---+---+---+\n";
    }
}

//handle an event! winning, getting/paying money, etc.
void handleEvent(const char board[ROWS][COLS], char player, int &playerMoney,
				 const int playerR, const int playerC) {
	switch (board[playerR][playerC]) {
		case 'A':
			cout << "A: Player " << player << " gained $65!\n";
			playerMoney+=65;
			break;
		case 'E': 
			cout << "E: Player " << player << " lost $3!\n";
			playerMoney-=3;
			break;
		case 'I': 
			cout << "I: Player " << player << " gained $8!\n";
			playerMoney+=8;
			break;
		case 'O': 
			cout << "O: Player " << player << " lost $300!\n";
			playerMoney-=300;
			break;
		case 'U': 
			cout << "U: Player " << player << " gained $200!\n";
			playerMoney+=200;
			break;
		default:
			cout << "The game is over!\n";
			break;
	}
}

//play a turn yaaay
void playTurn(const char board[ROWS][COLS], char player, int &money, 
			  int &playerR, int &playerC, int &otherR, int &otherC) {
	//variables!
	int roll;
	char option;
	
	//print whose turn it is
	cout << "PLAYER " << player << ", IT'S YOUR TURN!\n\n";
	
	cout << "Press R to roll, or P to pass your turn: ";
	cin >> option;
	option = tolower(option);
	
	while (option!='r' && option!='p') {
		cout << "Not an option! Choose R or P, please: ";
		cin >> option;
		option = tolower(option);
	}
	
	if (option=='r') {		
		cout << "\nRolling the dice..." << endl;
		
		//user rolls dice
		roll = diceRoll();
		cout << "You rolled a " << roll << ".\n";
		
		//user moves, print board with their new position <3	
		playerC+=roll;
		
		//if player moves to another row :D
		if (playerC>5) {
			playerC-=6;
			playerR++;
		}
		
		//print board after player moved
		if (player=='1') printBoard(board, playerR, playerC, otherR, otherC);
		else printBoard(board, otherR, otherC, playerR, playerC);
		
		handleEvent(board, player, money, playerR, playerC);
		
		cout << "Your turn is over; now you have $" << money << ".\n\n";
	} else cout << "You chose to pass. That's cool.\n\n";
}

int main()
{
	char board[ROWS][COLS];
    int p1Row, p1Col, p2Row, p2Col;  // The players' current locations
    int p1Money = 0; //player 1 money!
    int p2Money = 0; //player 2 money!
    
    welcomeMessage();
    
    // Seed the random number generator for diceRoll and resetBoard
    srand(time(NULL));
    
    // initialize the board
    initBoard(board);

    // set some values for testing
    p1Row = 0;
    p1Col = 0;
    p2Row = 0;
    p2Col = 1;

    // display the board
    printBoard(board, p1Row, p1Col, p2Row, p2Col);
    
    while (!gameOver(p1Row,p2Row)) {
		playTurn(board, '1', p1Money, p1Row, p1Col, p2Row, p2Col);
		if (!gameOver(p1Row,p2Row)) playTurn(board, '2', p2Money, p2Row, p2Col, p1Row, p1Col);
	}
	
	displayWinner(p1Money,p2Money);
	
    cout << endl;
    return 0;
}
