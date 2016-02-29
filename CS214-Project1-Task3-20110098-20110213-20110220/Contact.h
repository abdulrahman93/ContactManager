//#ifndef CONTACT_H_
//#define CONTACT_H_
#pragma once
#include<string>
#include "LinkedList.h"
using namespace std;
class Contact {
//private:
public:
	string name;
	LinkedList<string> phone_numbers;
public:
	Contact(){ name=""; }
	Contact(string name){ this->name=name;}
	void addPhoneNumber(string number){
	    cout << " HERE : " << name << endl ;
	    this->phone_numbers.addToList(number) ;

//        cout << " <=> " << this->phone_numbers.getHead()->getData().getName() ;

//	    cout << "SHIT\n" ;
	}
	string getName(){ return name ; }



/*    void operator= (Contact &ob )
    {
        name = ob.name ;

        Node<string>* ptr = ob.phone_numbers.getHead() ;

        while( ptr != NULL )
        {
            phone_numbers.addToList( ptr->getData() ) ;
        //    cout << ptr->getData() ;
            ptr = ptr->getNext() ;
        }



    }
*/
	bool operator< ( Contact &c){
        return ( this->getName() < c.getName() ) ;
	}

	bool operator== ( Contact & c){
	    return ( this->getName() == c.getName() ) ;
	}

	void print()
	{
	    cout << name << ": " << endl ;
	    Node<string>* ptr = phone_numbers.getHead() ;

	    while( ptr != NULL )
        {
            cout << ptr->getData() << endl ;
            ptr = ptr->getNext() ;
        }
	}
	friend ostream& operator<<(ostream& o, Contact & c){
	o << c.name << endl;
	o << "Phones: ";
	Node<string>* first = c.phone_numbers.getHead() ;
          while( first != NULL )
          {
              o << first->getData() << "-" ;
              first = first->getNext() ;
          }

    return o;
        }
};

//#endif  /* CONTACT_H_ */
