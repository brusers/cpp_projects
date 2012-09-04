#ifndef PLAYERCLASS_H
#define PLAYERCLASS_H

#include <string>

using namespace std;

class Player{
	public:
		Player();
		char name[10];
		int answer;
		int score;
		void printScore();
};

#endif
