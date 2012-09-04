#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib> 
#include <ctime> 
#include "rapidxml-1.13/rapidxml.hpp"

using namespace rapidxml;
using namespace std;

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


int main(void){
	int Qcount = 1;
	const int Q_asked = 6;
	int List[Q_asked] = {0};
	string gotten_rand;
	xml_document<> doc;
	xml_node<> * root_node;

	// Read the xml file into a vector
	ifstream theFile ("trivia.xml");
	vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
	buffer.push_back('\0');

	// Parse the buffer using the xml file parsing library into doc
	doc.parse<0>(&buffer[0]);

	// Find our root node
	root_node = doc.first_node("QuestionList");

	while (Qcount < Q_asked){
		List[Qcount] = get_Q_number(List, Qcount);
		List[Qcount] = get_Q_number(List, Qcount);
		stringstream out;
		out << List[Qcount];
		gotten_rand = out.str();
		
		for (xml_node<> * question_node = root_node->first_node("Question"); question_node; question_node = question_node->next_sibling()){
			string current = question_node->first_attribute("number")->value();
			
			if (current == gotten_rand){
				printf("%s\n", question_node->first_attribute("question")->value());
				// Interate over the answers
				for(xml_node<> * answer_node = question_node->first_node("Answer"); answer_node; answer_node = answer_node->next_sibling()){
					printf("\n %s \n %s \n %s \n %s \n",
					answer_node->first_attribute("A1")->value(),
					answer_node->first_attribute("A2")->value(),
					answer_node->first_attribute("A3")->value(),
					answer_node->first_attribute("A4")->value());
				}
				cout << endl;
			}
			
		}
		Qcount++;
	}
}


