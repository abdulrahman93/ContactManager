


#include<iostream>
#include "LinkedList.h"
#include "Contact.h"

template<class T>

LinkedList<T>::LinkedList(){
     head = NULL ;
}

//Node<T>* LinkedList<T>::addSorted(T v);
//Node* LinkedList<T>::get(T v);

template<class T>
Node<T>* LinkedList<T>:: addToList( T &item ){

   // cout << "HERE " ;

     Node<T>* newNode = new Node<T> ( item , NULL );
     Node<T>* nPtr = head , *pPtr = head ;

   if(head == NULL ){

     head = newNode ;
     head->setNext(NULL);

     return newNode ;
    }



//     cout << ":O \n" ;


    T c = nPtr->getData() ;

    bool b = 0 ;
    while( nPtr != NULL && c < item ){

        b = 1 ;
        pPtr = nPtr ;
        nPtr = nPtr->getNext() ;

        if( nPtr == NULL )
            break ;

        c = nPtr->getData() ;
    }
    if( c == item )
       return nPtr ;

     if( pPtr == head && nPtr != head ){

         newNode->setNext( nPtr ) ;
         pPtr->setNext( newNode ) ;
     }
     else if( /*( pPtr == head && nPtr == head && nPtr->getNext() != NULL ) ||*/ b == 0 ){
         newNode->setNext( nPtr ) ;
         head = newNode ; //pPtr->setNext( newNode ) ;
     }
     else if( pPtr->getNext() != NULL ){
         newNode->setNext( pPtr->getNext() ) ;
         pPtr->setNext( newNode ) ;
     }
     else{
         pPtr->setNext( newNode ) ;
         newNode->setNext( NULL ) ;
     }


    return newNode ;
}

    // operator overloading for printing
//      friend ostream& operator<<(ostream& o, LinkedList<T> & c);

