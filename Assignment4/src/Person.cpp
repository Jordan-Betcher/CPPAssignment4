/*
 * Person.cpp
 *
 *  Created on: Nov 20, 2017
 *      Author: Betcher
 */

#include "Person.h"

Person::Person()
{
	this->firstName = "";
	this->lastName = "";
	this->phone = "";
	
}

Person::Person(std::string firstName, std::string lastName)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->phone = "";
}

Person::Person(std::string firstName, std::string lastName, std::string phone)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->phone = phone;
}

Person::Person(Person name, std::string phone)
{
	this->firstName = name.firstName;
	this->lastName = name.lastName;
	this->phone = phone;
}

std::ostream& operator<<(std::ostream& output, Person& person)
{
	output << person.firstName << " " << person.lastName << ": "
	        << person.phone;
	return output;
}

std::string Person::getFirstName()
{
	return firstName;
}

std::string Person::getLastName()
{
	return lastName;
}

std::string Person::getPhone()
{
	return phone;
}

bool Person::hasPhone()
{
	return phone != "";
}

void Person::setPhone(std::string phone)
{
	this->phone = phone;
}

//Tells if two passengers match by their first and last name.
bool operator==(Person& firstPerson, Person& secondPerson)
{
	bool firstNameMatch = (firstPerson.firstName == secondPerson.firstName);
	bool lastNameMatch = (firstPerson.lastName == secondPerson.lastName);
	bool sameName = (firstNameMatch && lastNameMatch);
	return sameName;
}

//Tells if two passengers don't match by their first and last name.
bool operator!=(Person& firstPerson, Person& secondPerson)
{
	bool samePerson = (firstPerson == secondPerson);
	return (!samePerson);
}

//Tells if a passenger lastName is smaller (closer to a) than another passengers.
bool operator<(Person& firstPerson, Person& secondPerson)
{

	if (firstPerson.firstName < secondPerson.firstName)
	{
		return true;
	}
	else if (firstPerson.firstName == secondPerson.firstName)
	{
		return firstPerson.lastName < secondPerson.lastName;
	}
	else
	{
		return false;
	}
}

//Tells if a passenger lastName is larger (closer to a) than another passengers.
bool operator>(Person& firstPerson, Person& secondPerson)
{
	if (firstPerson.firstName > secondPerson.firstName)
	{
		return true;
	}
	else if (firstPerson.firstName == secondPerson.firstName)
	{
		return firstPerson.lastName > secondPerson.lastName;
	}
	else
	{
		return false;
	}
}

Person::~Person()
{
	this->firstName = "";
	this->lastName = "";
	this->phone = "";
}
