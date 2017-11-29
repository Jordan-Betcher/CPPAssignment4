/*
 * Person.cpp
 *
 *  Created on: Nov 20, 2017
 *      Author: Betcher
 */

#include "Person.h"

//Creates an empty person
Person::Person()
{
	this->mFirstName = "";
	this->mLastName = "";
	this->mPhone = "";
	
}

//Creates a person with only firstName and lastName
Person::Person(std::string firstName, std::string lastName)
{
	this->mFirstName = firstName;
	this->mLastName = lastName;
	this->mPhone = "";
}

//Creates a Person with firstName, lastName, and phone
Person::Person(std::string firstName, std::string lastName, std::string phone)
{
	this->mFirstName = firstName;
	this->mLastName = lastName;
	this->mPhone = phone;
}

//Creates a Person with firstName, lastName, and phone
Person::Person(Person name, std::string phone)
{
	this->mFirstName = name.mFirstName;
	this->mLastName = name.mLastName;
	this->mPhone = phone;
}

//Gets the firstName
std::string Person::getFirstName()
{
	return mFirstName;
}

//Gets the lastName
std::string Person::getLastName()
{
	return mLastName;
}

//Gets the phone
std::string Person::getPhone()
{
	return mPhone;
}

//Returns whether or not this Person has a phone
bool Person::hasPhone()
{
	return mPhone != "";
}

//Sets the phone of the Person
void Person::setPhone(std::string phone)
{
	this->mPhone = phone;
}

//Allows you to print to output
std::ostream& operator<<(std::ostream& output, Person& person)
{
	output << person.mFirstName << " " << person.mLastName << ": "
	        << person.mPhone;
	return output;
}

//Tells if two Persons match by their first and last name.
bool operator==(Person& firstPerson, Person& secondPerson)
{
	bool firstNameMatch = (firstPerson.mFirstName == secondPerson.mFirstName);
	bool lastNameMatch = (firstPerson.mLastName == secondPerson.mLastName);
	bool sameName = (firstNameMatch && lastNameMatch);
	return sameName;
}

//Tells if two Persons don't match by their first and last name.
bool operator!=(Person& firstPerson, Person& secondPerson)
{
	bool samePerson = (firstPerson == secondPerson);
	return (!samePerson);
}

//Tells if a Person is smaller than another, for sorting purposes.
bool operator<(Person& firstPerson, Person& secondPerson)
{

	if (firstPerson.mFirstName < secondPerson.mFirstName)
	{
		return true;
	}
	else if (firstPerson.mFirstName == secondPerson.mFirstName)
	{
		return firstPerson.mLastName < secondPerson.mLastName;
	}
	else
	{
		return false;
	}
}

//Tells if a Person is larger than another, for sorting purposes.
bool operator>(Person& firstPerson, Person& secondPerson)
{
	if (firstPerson.mFirstName > secondPerson.mFirstName)
	{
		return true;
	}
	else if (firstPerson.mFirstName == secondPerson.mFirstName)
	{
		return firstPerson.mLastName > secondPerson.mLastName;
	}
	else
	{
		return false;
	}
}

//Deletes the Person
Person::~Person()
{
	this->mFirstName = "";
	this->mLastName = "";
	this->mPhone = "";
}
