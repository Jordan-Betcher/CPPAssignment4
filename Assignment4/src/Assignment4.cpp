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
#include "Phonebook.h"
#include <vector>
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
	Phonebook phoneBook;

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
			phoneBook.add(person);
		}
		else if(input == "L")
		{
			string fileName;

			cout << "Enter file name: ";
			cin >> fileName;

			phoneBook.loadFile(fileName);
		}
		else if(input == "S")
		{
			string firstName, lastName;
			string phoneNumber;

			cout << "Enter name: ";
			cin >> firstName;
			cin >> lastName;

			Person person(firstName, lastName, "");
			phoneBook.search(person);
		}
		else if(input == "P")
		{
			phoneBook.print();
		}
		else if(input == "F")
		{
			string firstName, lastName;
			cout << "Enter name: ";
			cin >> firstName;
			cin >> lastName;

			Person person(firstName, lastName, "");

			phoneBook.filter(person);
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
