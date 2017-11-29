/*
 * Phonebook.cpp
 *
 *  Created on: Nov 29, 2017
 *      Author: Betcher
 */

#include "Phonebook.h"
#include <fstream>

//Creates the phonebook
Phonebook::Phonebook()
{
	
}

//Gets a Person from output and adds them  to the BinarySearchTree
void Phonebook::add()
{
	Person person = getPerson();
	mPersons.insert(person);
}

//Loads a file of Persons into the BinarySearchTree
void Phonebook::loadFile()
{
	string fileName;

	cout << "Enter file name: ";
	cin >> fileName;

	ifstream inputFile;
	string firstName;
	string lastName;
	string phone;

	inputFile.open(fileName);

	while (!inputFile.eof())
	{
		inputFile >> firstName;
		inputFile >> lastName;
		inputFile >> phone;

		Person person(firstName, lastName, phone);

		mPersons.insert(person);
	}

	inputFile.close();
}

//Searches for Person and prints their phone number
void Phonebook::search()
{
	Person person = getNamePerson();
	if (mPersons.contains(person))
	{
		Person found = mPersons.search(person);
		cout << "Phone: " << found.getPhone() << endl;
	}
	else
	{
		cout << "Person not found, please try again." << endl;
	}
}

//Prints all of the People
void Phonebook::print()
{
	vector<Person> people = mPersons.getInOrder();

	for (int i = 0; i < people.size(); i++)
	{
		cout << people[i] << endl;
	}

	int numberOfPersons = mPersons.getNodeCount();
	if (numberOfPersons == 0)
	{
		cout << "No contacts found." << endl;
	}
	else if (numberOfPersons == 1)
	{
		cout << "1" << " contact..." << endl;
	}
	else
	{
		cout << numberOfPersons << " contacts..." << endl;
	}
}

//Prints all of the People until it finds the Person
void Phonebook::filter()
{
	Person person = getNamePerson();
	vector<Person> people = mPersons.getInOrder();
	if (mPersons.contains(person))
	{
		int numberOfPersons = 0;

		for (numberOfPersons = 0; people[numberOfPersons] != person;
		        numberOfPersons++)
		{
			cout << people[numberOfPersons] << endl;
		}

		if (numberOfPersons == 1)
		{
			cout << "1" << " contact..." << endl;
		}
		else
		{
			cout << numberOfPersons << " contacts..." << endl;
		}

	}
	else
	{
		cout << "No contacts found." << endl;
	}
}

//returns a Person from input with only a name
Person Phonebook::getNamePerson()
{
	string firstName, lastName;

	cout << "Enter name: ";
	cin >> firstName;
	cin >> lastName;

	Person person(firstName, lastName);

	return person;
}

//Returns a phone from input
std::string Phonebook::getPhone()
{
	string phone;
	cout << "Enter phone: ";
	cin >> phone;
	return phone;
}

//Returns a Person from input
Person Phonebook::getPerson()
{
	Person person = getNamePerson();

	std::string phone = getPhone();
	person.setPhone(phone);
	return person;
}

//Searches for a Person and prints their phone
void Phonebook::search(Person person)
{
		if (mPersons.contains(person))
		{
			Person found = mPersons.search(person);
			cout << "Phone: " << found.getPhone() << endl;
		}
		else
		{
			cout << "Person not found, please try again." << endl;
		}
}

Phonebook::~Phonebook()
{
}
