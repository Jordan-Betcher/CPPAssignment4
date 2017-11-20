//============================================================================
// Name        : Assignment4.cpp
// Author      : Jordan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
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
	bool running = true;

	while (running)
	{
		string input;
		cout
		        << "A(Add) | L(Load) | S(Search) | P(Print) | F(Filter) | Q(Quit): ";
		cin >> input;

		if(input == "A")
		{

		}
		else if(input == "L")
		{

		}
		else if(input == "S")
		{

		}
		else if(input == "P")
		{

		}
		else if(input == "F")
		{

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
