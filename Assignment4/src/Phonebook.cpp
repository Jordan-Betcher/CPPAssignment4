/*
 * Phonebook.cpp
 *
 *  Created on: Nov 29, 2017
 *      Author: Betcher
 */

#include "Phonebook.h"
#include <fstream>

Phonebook::Phonebook()
{
	
}

void Phonebook::add()
{
	Person person = getPerson();
	persons.insert(person);
}

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

		persons.insert(person);
	}

	inputFile.close();
}

void Phonebook::search()
{
	Person person = getNamePerson();
	if (persons.contains(person))
	{
		Person found = persons.search(person);
		cout << "Phone: " << found.getPhone() << endl;
	}
	else
	{
		cout << "Person not found, please try again." << endl;
	}
}

void Phonebook::print()
{
	vector<Person> people = persons.inOrder();

	for (int i = 0; i < people.size(); i++)
	{
		cout << people[i] << endl;
	}

	int numberOfPersons = persons.nodeCount();
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

void Phonebook::filter()
{
	Person person = getNamePerson();
	vector<Person> people = persons.inOrder();
	if (persons.contains(person))
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

Person Phonebook::getNamePerson()
{
	string firstName, lastName;

	cout << "Enter name: ";
	cin >> firstName;
	cin >> lastName;

	Person person(firstName, lastName);

	return person;
}

std::string Phonebook::getPhone()
{
	string phone;
	cout << "Enter phone: ";
	cin >> phone;
	return phone;
}

Person Phonebook::getPerson()
{
	Person person = getNamePerson();

	std::string phone = getPhone();
	person.setPhone(phone);
	return person;
}

Phonebook::~Phonebook()
{
}
