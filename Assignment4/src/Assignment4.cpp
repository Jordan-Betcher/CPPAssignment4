//============================================================================
// Name        : Assignment4.cpp
// Author      : Jordan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Person.h"
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
	BinarySearchTree<Person> persons;

	bool running = true;

	while (running)
	{
		string input;
		cout << "A(Add) | L(Load) | S(Search) | P(Print) | F(Filter) | Q(Quit): ";
		cin >> input;

		if(input == "A")
		{
			string name;
			string phone;

			cout << "Enter name: " << endl;
			getline(cin, name);

			cout << "Enter phone: " << endl;
			cin >> phone;

			Person person(name, phone);

			persons.insert(person);
		}
		else if(input == "L")
		{
			string fileName;

			cout << "Enter file name: " << endl;
			cin >> fileName;

			//Load file into BinarySearchTree

		}
		else if(input == "S")
		{
			string firstName;
			string lastName;
			string phoneNumber;

			cout << "Enter name: " << endl;
			cin >> firstName;
			cin >> lastName;

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
