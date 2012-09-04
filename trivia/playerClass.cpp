#include <iostream>
#include "playerClass.h"

using namespace std;

Player::Player()
{
	score = 0;
}

void Player::printScore(){
	cout << score << endl;
}
