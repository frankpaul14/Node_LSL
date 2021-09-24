#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <sstream>
#include "nodo.h"

using namespace std; 

template <class T> 
class List{
    private: 
        Node<T> * head;
        int length;

    public: 
        List (Node<T> * head) : head(head), length(0){}
        List() : List (NULL) {}
    
    void insert( Node<T> * n) {
        if ( head == NULL ){
            head = n; 
            length++;
            return; 
        }
        Node<T> * current = head;
        while(current->getNext() != NULL){  // finche il successore non è null 
            current = current ->getNext();
            length++;

        } 
        current -> setNext(n); 
    }

    int getLength(){
        return this->length;
    }

    Node<T> * getHead(){
         return this->head;
    }

    friend ostream& operator<<(ostream& out, List<T> l){
        out<< "Lista di lunghezza : "<<l.length <<" head "<< l.head << endl;
        Node<T> * current = l.head;
        while(current != NULL){
            out<<"\t"<< current->toString()<<endl;
            current = current-> getNext();
        }
        return out; 
    }

    void insert (T value){
        Node<T> * temp = new Node<T>(value); // in questo modo lo sto creando 
        this-> insert (temp);
    }

    void insertInOrder(T value,bool ascend){
        Node<T> * temp = new Node<T> (value);
        if (head == NULL){
            this-> insert(temp);
            cout<< "NON Cè inserisco"<<endl; 
            return;
        }
        if (ascend) {
            if( head-> getValue() >= value){ //se il valore che head sta puntando è maggiore del valore che voglio inserire, allora: 
                    temp -> setNext(head); // metti in temp la posizione di head successiva 
                    head = temp;  // assegna ad head il valore di temp 
                    cout<< "IF HEAD GETVALUE()"<<endl;
                    length++;
                    return;
                }
            } 
            else{
                if( head-> getValue() < value){ //se il valore che head sta puntando è maggiore del valore che voglio inserire, allora: 
                 temp -> setNext(head); // metti in temp la posizione di head successiva 
                    head = temp;  // assegna ad head il valore di temp 
                    cout<< "IF HEAD GETVALUE()"<<endl;
                    length++;
                    return;
                }
        }

        Node<T> * prev = head; // puntatore per scorrere la lista 
        Node<T> * current = head->getNext();  // puntatore per scorrere la lista 
                                    // scorre tutta la lista fino a quando lo deve inserire tra due valori , altrimenti è il più grande e lo inserisce nell'ultima posizione
        while (current != NULL){ // scorro tutta la lista , se è finita e punto a NULL vuoldire che il valore che ho in quel momento è il più grane di tutti e deve essere inserito neella posizione di NULL !!!!
            if (ascend){
                if ( prev->getValue()< value && current-> getValue()>= value){
                    prev->setNext(temp);
                    temp->setNext(current);
                    length++; 
                    return;
                }
                else{
                    prev = current;
                    current = current->getNext();
                }
            }
            else {
                if ( prev->getValue()>= value && current-> getValue()< value){
                    prev->setNext(temp);
                    temp->setNext(current);
                    length++; 
                    return;
                }
                else{
                    prev = current;
                    current = current->getNext();
                }

            }
        }
        prev -> setNext(temp);// ha fatto scorrere tutta la lista , il valore è più grande e arriva qui!!!!
        length++;
        return;
    }

    bool search(T value){
        
        if ( head == NULL){
            return false;
        }

        Node<T> * temp = head;
        while( temp != NULL){
            if (temp->getValue() == value)
                return true;
            temp= temp->getNext();
        }
        return false;
    }

    Node<T> * deleteNode (T value){

        if ( this->search(value)){
            if ( head->getValue() == value){
                Node<T> * temp = head;
                head = head->getNext();
                length--;
                return temp;
            }
            Node<T> * prev = head;
            Node<T> * current= head->getNext();

            while(current!=NULL){
                if (current->getValue() == value){
                    prev->setNext(current->getNext());
                    length--;
                    return current;
                }
                prev = current;
                current= current->getNext();
            }
        }
        return NULL;
    }
};

#endif 