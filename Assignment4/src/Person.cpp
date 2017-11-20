/*
 * Person.cpp
 *
 *  Created on: Nov 20, 2017
 *      Author: Betcher
 */

#include "Person.h"

Person::Person()
{
	this->name = "";
	this->phone = "";
}

Person::Person(std::string name, std::string phone)
{
	this->name = name;
	this->phone = phone;
}

std::string Person::getName()
{
	return this->name;
}

std::string Person::getPhone()
{
	return this->phone;
}

Person::~Person()
{
	this->name = NULL;
	this->phone = NULL;

}

