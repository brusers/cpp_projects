#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "rapidxml-1.13/rapidxml.hpp"
#include "playerClass.h"
#include "game_init.h"
#include "get_check.h"

using namespace rapidxml;
using namespace std;


int main(void){
	Player P1;
	Player P2;
	Player P3;
	Player P4;
	
	int Qcount = 1;
	const int Q_asked = 6;
	int List[Q_asked] = {0};
	string gotten_rand;
	int correctAnswer = 0;
	
	int Pcount = intro(Q_asked - 1);
	initialize_players(Pcount, P1, P2, P3, P4);
	
	xml_document<> doc;
	xml_node<> * root_node;
	ifstream theFile ("trivia.xml");						// Read the xml file into a vector
	vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
	buffer.push_back('\0');
	doc.parse<0>(&buffer[0]);								// Parse the buffer using the xml file parsing library into doc
	root_node = doc.first_node("QuestionList");				// Find our root node

	while (Qcount < Q_asked){
		system("clear");
	
		List[Qcount] = get_Q_number(List, Qcount);
		stringstream out;
		out << List[Qcount];
		gotten_rand = out.str();
		
		for (xml_node<>*question_node = root_node->first_node("Question");question_node;question_node = question_node->next_sibling()){
			string current = question_node->first_attribute("number")->value();
			
			if (current == gotten_rand){
				printf("%s\n", question_node->first_attribute("question")->value());
				xml_node<> * answer_node = question_node->first_node("Answer");
				printf("\n %s \n %s \n %s \n %s \n",
				answer_node->first_attribute("A1")->value(),
				answer_node->first_attribute("A2")->value(),
				answer_node->first_attribute("A3")->value(),
				answer_node->first_attribute("A4")->value());
				correctAnswer = atoi(answer_node->first_attribute("correct")->value());
				cout << endl;
				get_answers(Pcount, P1, P2, P3, P4);
				check_answer(Pcount, correctAnswer, P1, P2, P3, P4);
			}
		}
		Qcount++;
	}
	system("clear");
	cout << "The final scores are:" << endl;
	show_scores(Pcount, P1, P2, P3, P4);
}

