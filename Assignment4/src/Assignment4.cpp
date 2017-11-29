//============================================================================
// Name        : Assignment4.cpp
// Author      : Jordan Betcher
// Date		   : 11/29/2017
// Description : Runs a phonebook that keeps track of people
//============================================================================

#include <iostream>
#include "BinarySearchTree.h"
#include "Person.h"
#include "Phonebook.h"
#include <vector>
using namespace std;

void printIntro();
void runPhonebook();
void calculateElapseTime();

//Main function
int main()
{
	//printIntro();
	//runPhonebook();
	calculateElapseTime();
	return 0;
}

//Prints the intro
inline void printIntro()
{
	cout << "***MY PHONEBOOK APPLICATION***" << endl;
	cout << "Please choose an operation:" << endl;
}

//Runs the phone book
inline void runPhonebook()
{
	Phonebook phonebook;

	bool running = true;

	while (running)
	{
		string input;
		cout
		        << "A(Add) | L(Load) | S(Search) | P(Print) | F(Filter) | Q(Quit): ";
		cin >> input;

		if (input == "A")
		{
			phonebook.add();
		}
		else if (input == "L")
		{
			phonebook.loadFile();
		}
		else if (input == "S")
		{
			phonebook.search();
		}
		else if (input == "P")
		{
			phonebook.print();
		}
		else if (input == "F")
		{
			phonebook.filter();
		}
		else if (input == "Q")
		{
			cout << "Bye" << endl;
			running = false;
		}
		else
		{
			cout << "Could not understand your operation, please try again."
			        << endl;
		}
	}

}

//Calculates Elapsed Time of the BinarySearchTree in PhoneBook
void calculateElapseTime()
{

	Phonebook phonebook;
	phonebook.loadFile();
	Person person("MAUD", "SHAFRON");
	cout << person << endl;

	using namespace std;
	clock_t begin = clock();

	phonebook.search(person);

	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << elapsed_secs;
}

