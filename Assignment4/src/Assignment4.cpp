//============================================================================
// Name        : Assignment4.cpp
// Author      : Jordan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

void printIntro();
void runPhoneBook();

int main()
{
	printIntro();
	runPhoneBook();

	return 0;
}

inline void printIntro()
{
	cout << "***MY	PHONEBOOK	APPLICATION***" << endl;
	cout << "Please	choose	an	operation:" << endl;
}

inline void runPhoneBook()
{
	BinarySearchTree<string> persons;

	bool running = true;

	while (running)
	{
		string input;
		cout << "A(Add) | L(Load) | S(Search) | P(Print) | F(Filter) | Q(Quit): ";
		cin >> input;

		if(input == "A")
		{
			string firstName, lastName;
			string phone;

			cout << "Enter name: ";
			cin >> firstName;
			cin >> lastName;

			cout << "Enter phone: ";
			cin >> phone;

			string temp = firstName + " " + lastName + " " + phone;
			persons.insert(temp);
		}
		else if(input == "L")
		{
			string fileName;

			cout << "Enter file name: ";
			cin >> fileName;

			//Load file into BinarySearchTree

		}
		else if(input == "S")
		{
			string name;
			string phoneNumber;

			cout << "Enter name: ";
			getline(cin, name);

			//Print phone of person


		}
		else if(input == "P")
		{
			//Print BinarySearchTree
			//Print how many
		}
		else if(input == "F")
		{
			//??
		}
		else if(input == "Q")
		{
			cout << "Bye" << endl;
			running = false;
		}
		else
		{

		}
	}


}
