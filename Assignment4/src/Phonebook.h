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
		BinarySearchTree<Person> persons;
	public:
		Phonebook();
		void add(Person person);
		void loadFile(std::string fileName);
		void search(Person person);
		void print();
		void filter(Person person);
		virtual ~Phonebook();
};

#endif /* PHONEBOOK_H_ */
