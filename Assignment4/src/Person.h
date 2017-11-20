/*
 * Person.h
 *
 *  Created on: Nov 20, 2017
 *      Author: Betcher
 */

#ifndef PERSON_H_
#define PERSON_H_

#include <string>

class Person
{
	private:
		std::string name;
		std::string phone;

	public:
		Person();
		Person(std::string name, std::string phone);
		std::string getName();
		std::string getPhone();
		virtual ~Person();
};

#endif /* PERSON_H_ */
