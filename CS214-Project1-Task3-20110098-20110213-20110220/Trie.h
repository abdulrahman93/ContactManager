#pragma once
#include "Contact.h"
#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>
#define SZ(S) S.size()
using namespace std;

class TNode {
    char content ;
    bool mark ;
    vector<TNode*> children ;
    Node<Contact>* contact  ;

public:
    TNode(){
        content = ' ' ;
        mark = true ;
        }
    ~TNode(){}
    char getContent(){
        return content ;
        }
    void setContent(char ch){
        content = ch ;
        }
    bool IsMarked(){
        return mark ; }
    void setMark(){
        mark = true; }
    int getSize(){
        return SZ(children) ;
    }
   ///////////////////////////////////////////////
    TNode* findChild(char c){

    for (int i=0 ; i < SZ(children) ; i++)
    {
        TNode* tmp = children[i] ;
        if ( tmp->getContent() == c )
            return tmp ;
    }
    return NULL ;
}
    void appendChild(TNode* child) {
        children.push_back(child);
        sortchildren() ;
         }
    void sortchildren(){

//        cout << "DONE\n" ;
        sort( children.begin() , children.end() ) ;
    }
    vector<TNode*>& GetChildren() {
        return children ;
        }
    void setContact(Node<Contact>* &cu){
        contact = cu ;
    }

};

class Trie {

    TNode* root;
public:
    Trie();
    ~Trie();
    void addContact(string Name  , Node<Contact>* ptr );
    void searchForKey(string S);
    void printContacts(TNode* ptr) ;


};


// de function 34an t7awl ay name l-string of numbers :D
string ConvertIntoNums(string &S);
