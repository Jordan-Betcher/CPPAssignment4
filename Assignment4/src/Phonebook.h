/*
 * Phonebook.h
 *
 *  Created on: Nov 29, 2017
 *      Author: Betcher
 */

#ifndef PHONEBOOK_H_
#define PHONEBOOK_H_
#include <string>
#include "Person.h"
#include "BinarySearchTree.h"

class Phonebook
{
	private:
		BinarySearchTree<Person> mPersons;
		Person getNamePerson();
		std::string getPhone();
		Person getPerson();
	public:
		Phonebook();
		void add();
		void loadFile();
		void search();
		void search(Person person);
		void print();
		void filter();
		virtual ~Phonebook();
};

#endif /* PHONEBOOK_H_ */
