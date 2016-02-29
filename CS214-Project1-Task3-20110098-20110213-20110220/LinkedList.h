//#ifndef LINKED_LIST_H_
//#define LINKED_LIST_H_
#pragma once

#include<iostream>
#include<string>
using namespace std;

template<class T>
class Node {
public:
     T data ;
     Node* next ;

     Node () {next = NULL ; }
     Node (T dataItem, Node<T>* nextPtr = NULL ) {
       data = dataItem ; next = nextPtr ;
}

    void setNext( Node<T>* next ){ this->next = next ; }
   Node<T>* getNext(){
        return next ;
   }
   T& getData(){
        return data ;
   }

     Node(T v);
};


template<class T>
class LinkedList {

	Node<T>* head;
public:
	string delimeter; // optional: just for printing

	LinkedList();
	Node<T>* addSorted(T v);
	Node<T>* get(T v)
	{
	    Node<T>* root = head ;

	    while( root != NULL && !(root->getData() == v ) ){
            //cout << "Hello World !\n";
            root = root->getNext();

	    }



	    return root;
	}
	Node<T>* getHead(){ return head; }
	Node<T>* addToList( T &item );

	// operator overloading for printing
//	friend ostream& operator<<(ostream& o, LinkedList<T> & c);
};

//#endif  /* LINKED_LIST_H_ */
