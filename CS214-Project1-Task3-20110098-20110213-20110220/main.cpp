#include <iostream>
#include "ContactManager.h"
using namespace std;
int main()
{

    ContactManager c;

    string S = "all-contacts.in";
    c.loadFromFile( S );

  //  c.print() ;

//    c.displayContact("01197853383");

    return 0;
}


//    c.add("Diaa","123");
//    c.add("Zahra","123");
//    c.add("Adel","123876");
//    c.add("Magdi","435445");
//    c.add("Kamal","123");
//    c.add("A7md","123876");
//    c.add("Zahra","111");

//    Trie* trie = new Trie() ;
//
//    trie->addContact("aaa");
//    trie->addContact("a5dr");
//    trie->addContact("a7mr");

//    cout << trie->searchForKey("a7md") ;
