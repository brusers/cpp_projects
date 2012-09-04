#include <iostream>
#include "playerClass.h"
#include "get_check.h"

using namespace std;

void get_answers(int num, Player &P1, Player &P2, Player &P3, Player &P4){
	cout << "Time to give your answers..." << endl;
	cout << "Enter a number 1 - 4:" << endl << endl;
	switch(num){
		case 1:
			cout << P1.name << ", answer and press ENTER: ";
			cin >> P1.answer;
			break;
		case 2:
			cout << P1.name << ", answer and press ENTER: ";
			cin >> P1.answer;
			cout << P2.name << ", answer and press ENTER: ";
			cin >> P2.answer;
			break;
		case 3:
			cout << P1.name << ", answer and press ENTER: ";
			cin >> P1.answer;
			cout << P2.name << ", answer and press ENTER: ";
			cin >> P2.answer;
			cout << P3.name << ", answer and press ENTER: ";
			cin >> P3.answer;
			break;
		case 4:
			cout << P1.name << ", answer and press ENTER: ";
			cin >> P1.answer;
			cout << P2.name << ", answer and press ENTER: ";
			cin >> P2.answer;
			cout << P3.name << ", answer and press ENTER: ";
			cin >> P3.answer;
			cout << P4.name << ", answer and press ENTER: ";
			cin >> P4.answer;
			break;
	}
}


void check_answer(int num, int CA, Player &P1, Player &P2, Player &P3, Player &P4){
	switch(num){
		case 1:
			if (P1.answer == CA) P1.score++;
			break;
		case 2:
			if (P1.answer == CA) P1.score++;
			if (P2.answer == CA) P2.score++;
			break;
		case 3:
			if (P1.answer == CA) P1.score++;
			if (P2.answer == CA) P2.score++;
			if (P3.answer == CA) P3.score++;
			break;
		case 4:
			if (P1.answer == CA) P1.score++;
			if (P2.answer == CA) P2.score++;
			if (P3.answer == CA) P3.score++;
			if (P4.answer == CA) P4.score++;
			break;
	}
}

void show_scores(int num, Player &P1, Player &P2, Player &P3, Player &P4){
	switch(num){
		case 1:
			cout << P1.name << "	" << P1.score << endl;
			break;
		case 2:
			cout << P1.name << "	" << P1.score << endl;
			cout << P2.name << "	" << P2.score << endl;
			break;
		case 3:
			cout << P1.name << "	" << P1.score << endl;
			cout << P2.name << "	" << P2.score << endl;
			cout << P3.name << "	" << P3.score << endl;
			break;
		case 4:
			cout << P1.name << "	" << P1.score << endl;
			cout << P2.name << "	" << P2.score << endl;
			cout << P3.name << "	" << P3.score << endl;
			cout << P4.name << "	" << P4.score << endl;
			break;
	}
}
