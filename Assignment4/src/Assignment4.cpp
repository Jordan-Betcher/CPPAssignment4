//============================================================================
// Name        : Assignment4.cpp
// Author      : Jordan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "BinarySearchTree.h"
#include "Person.h"
#include <fstream>
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
	cout << "***MY PHONEBOOK APPLICATION***" << endl;
	cout << "Please choose an operation:" << endl;
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
			string firstName, lastName;
			string phone;

			cout << "Enter name: ";
			cin >> firstName;
			cin >> lastName;

			cout << "Enter phone: ";
			cin >> phone;

			Person person(firstName, lastName, phone);
			persons.insert(person);
		}
		else if(input == "L")
		{
			string fileName;

			cout << "Enter file name: ";
			cin >> fileName;

			ifstream inputFile;
			string firstName;
			string lastName;
			string phone;
			inputFile.open(fileName);
			while(inputFile.is_open())
			{
				inputFile >> firstName
				inputFile >> lastName;
				inputFile >> phone;

				Person person(firstName, lastName, phone);
				persons.insert(person);
			}
			inputFile.close();

		}
		else if(input == "S")
		{
			string firstName, lastName;
			string phoneNumber;

			cout << "Enter name: ";
			cin >> firstName;
			cin >> lastName;

			Person person(firstName, lastName, "");
			cout << persons.search(person) << endl;
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
			cout << "Could not understand your operation, please try again." << endl;
		}
	}


}
