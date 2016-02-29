#include <iostream>
# include <fstream>
#include "ContactManager.h"
using namespace std ;

ContactManager::ContactManager(){}


bool ContactManager::loadFromFile(string fileName){

    int  x = 0 ;
    fstream f ;
    char num[13] , name[2001] ;

    f.open( fileName.c_str() , ios::in );  //all-contacts.in
    if ( f.fail() ){
         cout << "Error opening File\n";
         return 0 ;
         }

    while( !f.eof() ){

        x++ ;
        f.getline(num, 12, ' ') ;
        f.getline(name, 200, '\n') ;
        add( name , num ) ;
    }

//    cout << x ;
    MakeTrie() ;

    //then you will call function of add, edit what you want
    f.close();
}

void ContactManager::add(string name, string phone_number){

     Contact c( name ) ;

    // (contacts.addToList(c) )->getData().phone_numbers.addToList(phone_number) ;
     Node<Contact>* cu = (contacts.addToList(c) ) ;
     cu->getData().phone_numbers.addToList(phone_number);

     tree.insert(phone_number,cu);
}


void ContactManager::displayNumber(string phone_number){
    //

}


void ContactManager::MakeTrie(){
    Node<Contact>* cu = contacts.getHead() ;
    while( cu != NULL )
    {
        trie->addContact( cu->getData().name , cu ) ;
        cu = cu->getNext() ;
    }
   // cout << "done" ;
}

//
void ContactManager::GetContact(string S){

    trie->searchForKey(S) ;
}

// for treap
void ContactManager::displayContact(string Phone_number){

    //
    Node<Contact>* ptr = tree.find(Phone_number) ;

    if( ptr != NULL )
        cout << " -> " << ptr->getData().name ;
    //This is addition in case of there's no name for this number
    else
        cout << Phone_number ;
}

void ContactManager::print(){

     cout << "Print Fun.\n";
     Node<Contact>* nPtr = contacts.getHead() ;

     int c = 0 ;
     while( nPtr != NULL)
     {
    //     cout << "here";
    //string cn = nPtr->getData().getName() ;
            cout << nPtr->getData() << endl;
          //cout << cn << endl;
/*************************  my edit 34an ygeeb 2li gwa kol contact **************************************/

          /*Node<string>* first = nPtr->getData().phone_numbers.getHead() ;
          while( first != NULL )
          {
              cout << first->getData() << " " ;
              first = first->getNext() ;
          }
            cout << "\n-----\n";*/

          nPtr = nPtr->getNext() ;
          c++ ;
     }
     cout << " - Unique Names : " << c ;

}
//friend ostream& operator<<(ostream& o, ContactManager & c);
