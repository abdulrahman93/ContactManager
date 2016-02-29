#include "Trie.h"
#define SZ(S) S.size()
using namespace std ;


//////////////////////////////////////////////
Trie::Trie(){
    root = new TNode();
}
//////////////////////////////////////////////
Trie::~Trie(){
    // Free memory
}
//////////////////////////////////////////////
void Trie::addContact(string Name , Node<Contact>* cu ){
    string S = ConvertIntoNums(Name) ;
    TNode* current = root;

    if ( SZ(S) == 0 )
    {
        current->setMark() ;
        return ;
    }
    for (int i=0 ; i < SZ(S) ; i++)
    {
        TNode* child = current->findChild( S[i] ) ;
        if ( child != NULL )
            current = child ;
        else
        {
            TNode* tmp = new TNode() ;
            tmp->setContent( S[i] ) ;
            current->appendChild( tmp ) ;
            current = tmp;
        }
        if ( i == SZ(S) - 1 ) ;
           current->setContact(cu) ;
        

    }
}
//////////////////////////////////////////////
void Trie::searchForKey(string S){

    TNode* current = root ;

    for (int i=0 ; i< SZ(S) ; i++)
    {
        TNode* tmp = current->findChild( S[i] ) ;
        if ( tmp == NULL ){
            cout << "There's no Contact for this Key. \n" ;
            return ;
        }
        current = tmp ;
    }
}
    
void Trie::printContacts(TNode* ptr){

    vector<TNode*> chil = ptr->GetChildren() ;
    for(int i=0 ; ptr->getSize() ; i++)
    {
        printContacts( chil[i] ) ;
    }
    
}
//////////////////////////////////////////////
string ConvertIntoNums(string &S){

    string T = "" ;
    char ch ;
    for(int i=0 ; i<SZ(S) ; i++)
    {
        ch = tolower( S[i] ) ;
        if( ch >= 'a' && ch <= 'c' )
            T += '2' ;
        else if( ch >= 'd' && ch <= 'f' )
            T += '3' ;
        else if( ch >= 'g' && ch <= 'i' )
            T += '4' ;
        else if( ch >= 'j' && ch <= 'l' )
            T += '5' ;
        else if( ch >= 'm' && ch <= 'o' )
            T += '6' ;
        else if( ch >= 'p' && ch <= 's' )
            T += '7' ;
        else if( ch >= 't' && ch <= 'v' )
            T += '8' ;
        else if( ch >= 'w' && ch <= 'z' )
            T += '9' ;
        else
            T += '0' ;
    }

    return T ;
}
