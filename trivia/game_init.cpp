#include <iostream>
#include <cstdlib> 
#include "playerClass.h"
#include "game_init.h"

using namespace std;

void initialize_players(int num, Player &P1, Player &P2, Player &P3, Player &P4){
	system("clear");
	cout << endl << "After players names are entered the questions will begin.." << endl << endl;
	switch(num){
		case 1:
			cout << "Enter a name for Player 1 and press ENTER: ";
			cin >> P1.name;
			break;
		case 2:
			cout << "Enter a name for Player 1 and press ENTER: ";
			cin >> P1.name;
			cout << "Enter a name for Player 2 and press ENTER: ";
			cin >> P2.name;
			break;
		case 3:
			cout << "Enter a name for Player 1 and press ENTER: ";
			cin >> P1.name;
			cout << "Enter a name for Player 2 and press ENTER: ";
			cin >> P2.name;
			cout << "Enter a name for Player 3 and press ENTER: ";
			cin >> P3.name;
			break;
		case 4:
			cout << "Enter a name for Player 1 and press ENTER: ";
			cin >> P1.name;
			cout << "Enter a name for Player 2 and press ENTER: ";
			cin >> P2.name;
			cout << "Enter a name for Player 3 and press ENTER: ";
			cin >> P3.name;
			cout << "Enter a name for Player 4 and press ENTER: ";
			cin >> P4.name;
			break;
	}		
}


int intro(int num){
	int input;
	system("clear");
	cout << endl;
	cout << "***			Trivia madness!			***" << endl << endl;
	cout << "The rules:" << endl << endl;
	cout << "	- You can have up to four players at a time." << endl;
	cout << "	- You will have " << num << " questions asked." << endl;
	cout << "	- Each player will get a chance at the question before the answer is given." << endl;
	cout << "	- The player with the most correct answers wins!" << endl << endl << endl << endl;
	cout << "Enter the number of players and press ENTER to play! (1 to 4): ";
	cin>>input;
	return input;
}

int get_rand(){
	int Q_List_size = 10;
	srand((unsigned)time(0)); 
	int myRandom = (rand()%Q_List_size)+1;
	return myRandom;
}


int get_Q_number(int *myList, int mySize){
	int myTest = get_rand();
	for(int i=0; i<mySize; i++){
		if(myTest == myList[i]){
			myTest = get_rand();
			i = 0;
		}
	}
	return myTest;
}
