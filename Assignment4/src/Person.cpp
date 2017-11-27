/*
 * Person.cpp
 *
 *  Created on: Nov 20, 2017
 *      Author: Betcher
 */

#include "Person.h"

Person::Person()
{
	

}

Person::Person(std::string firstName, std::string lastName, std::string phone)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->phone = phone;
}

Person::~Person()
{
	// TODO Auto-generated destructor stub
}

std::ostream& operator<<(std::ostream& output, Person& person)
{
	output << person.firstName << " " << person.lastName << ": " << person.phone;
	return output;
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

	if(firstPerson.firstName < secondPerson.firstName)
	{
		return true;
	}
	else if(firstPerson.firstName == secondPerson.firstName)
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
	if(firstPerson.firstName > secondPerson.firstName)
	{
		return true;
	}
	else if(firstPerson.firstName == secondPerson.firstName)
	{
		return firstPerson.lastName > secondPerson.lastName;
	}
	else
	{
		return false;
	}
}

std::string Person::getPhone()
{
	return phone;
}

std::string Person::getFirstName()
{
	return firstName;
}

std::string Person::getLastName()
{
	return lastName;
}
