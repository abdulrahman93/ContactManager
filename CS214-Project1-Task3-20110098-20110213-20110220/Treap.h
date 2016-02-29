#include<iostream>
#include<string>
#include<time.h>
#include <stdlib.h>

using namespace std;

template<class T, class V>
class Treap
{
public:
    class Node
    {
    public:
        Node *left, *right;
        T key;
        V value;
        int priority;
        T getK(){
            return key;
        }
        V getV(){
            return value;
        }
        Node(T k, V v){
            key=k;
            value=v;
        }
        friend ostream& operator<<(ostream &o, Treap<T, V>::Node root){

            o<<"root.value  = " <<root.value;
            o<<"   , root.key "<<root.key;
            o<<"   root.priority  "<<root.priority;
            o<<"  , root.left "<<root.left;
            o<< "   root.right"<<root.right<<endl;
            return o;
        }
    };
private:
    Node* root;
    Node* rotateLeft(Node* K2){
        Node* K1= K2->left;
        K2->left = K1->right;
        K1->right = K2;
        return K1;  /* New root */
    }
    Node* rotateRight(Node* K1){
        Node *K2 = K1->right;
        K1->right = K2->left;
        K2->left = K1;
        return K2;  /* New root */
    }

    Node* insert(Node* &n, T k, V v){
        if( n == NULL )
        {
            Node *r = new Node(k,v);
            r->priority = rand()% 100 + 1;
            //  cout<<"priority "<<r->priority<<endl;
            r->left = r->right = NULL;
            n=r;
        }
        else if( k < n->key )
        {
            // cout<<"LEFT"<<endl;
            n->left = insert(n->left , k , v);
            if( n->left->priority > n->priority )
                n = rotateLeft( n );
            // cout<<"rotateLeft"<<endl;
        }
        else if( k > n->key )
        {
            //  cout<<"RIGHT"<<endl;
            n->right = insert( n->right , k , v);
            if( n->right->priority > n->priority )
            {
                //cout<<"rotateRight"<<endl;
                n = rotateRight ( n );
            }
        }
        return n;
    }

    void inorder (Node *n ){
        if (n == NULL)
            return;
        inorder (n->left);
        cout<<n->getV()<<"  "<<n->getK()<<endl;;
        inorder (n->right);
    }

    Node* find(Node* r, T k){

        if( r == NULL )
            return NULL;
        else if(k == r->key)
            return r;
        else if( k < r->key )
            return find( r->left , k);
        else if( k > r->key )
            return find(r->right , k);
    }

public:

    Treap(){
        root=NULL;
        srand (time(NULL));
//        cout<<"TREAP"<<endl;
    }

    void insert(T k, V v){
        Node* U = insert(root, k, v);
    }


    V find(T k){
        Node* s =find(root,k);
        if(s==NULL) return 0;
        return s->getV();
    }

    void inorder (){
        inorder (root);
    }

};
