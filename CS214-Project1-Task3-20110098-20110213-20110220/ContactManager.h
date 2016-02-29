//#ifndef CONTACT_MANAGER_H_
//#define CONTACT_MANAGER_H_

#pragma once

#include "LinkedList.cpp"
#include "Contact.cpp"
#include "Treap.h"  // for Task 2
#include "Trie.h"


class ContactManager {
private:
	LinkedList<Contact> contacts;
	Treap<string, Node<Contact>* > tree;  // for Task 2
    Trie* trie = new Trie();
public:
	ContactManager();
	bool loadFromFile(string fileName);
	void add(string name, string phone_number);
	void displayNumber(string phone_number);
    void displayContact(string Phone_number);
	void print();
    void MakeTrie() ;
	void GetContact(string S);
	friend ostream& operator<<(ostream& o, ContactManager & c);
};

//#endif  /* CONTACT_MANAGER_H_ */
