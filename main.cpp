#include "nodo.h"
#include <iostream>
#include "list.h"
#include "studente.h"
using namespace std;

int main(){
    Node<int> n0(10);
    Node<int> n1(11);
    Node<int> n2;
    
    cout << &n0 << endl;
    cout << &n1 << endl;
    cout << &n2 << endl;
    cout << n0.getValue() << endl;
    cout << n0.getNext() << endl;
    
   // n2.setValue(100);
    //n2.setNext(&n0);
    
    cout << n1.toString() << endl;
    bool ascend = false; 


    List<int> list;
    list.insertInOrder(9,ascend);
    cout<<list<<endl;
    list.insertInOrder(3,ascend);
    cout<<list<<endl;
    list.insertInOrder(2,ascend);
    cout<<list<<endl;
    list.insertInOrder(1,ascend);
    cout<<list<<endl;
    list.insertInOrder(19,ascend);
    cout<<list<<endl;
    list.insertInOrder(4,ascend);
    cout<<list<<endl;
    list.insertInOrder(20,ascend);
    cout<<list<<endl;
    list.deleteNode(5);
    cout<<list<<endl;
    list.deleteNode(1);
    cout<<list<<endl;
    list.deleteNode(20);
    cout<<list<<endl;

    Studente s1("a","a","a",20);
    Studente s2("b","a","a",20);
    Studente s3("a","b","a",20);
    Studente s4("a","a","a",21);
/*
    cout<< (s1<s2)<< endl; //true
    cout<< (s1>s2) << endl; //false
    cout<< (s1>s3) << endl; //false
    cout<< (s3>s2) << endl; //true
    cout<< (s1>s4) << endl; //false 
    cout<< (s1==s1) << endl; //true */
    /*
    list.insert(&n0);
    list.insert(&n1);
    list.insert(&n2);
    list.insert(14);*/

    //cout<< list<< endl;  
    
    List <Studente> list2;
    list2.insertInOrder(s1, !ascend);
    cout<< list2<<endl;
    list2.insertInOrder(s2,!ascend);
    cout<< list2<<endl;
    list2.insertInOrder(s3,!ascend);
    cout<< list2<<endl;
    list2.insertInOrder(s4,!ascend);
    cout<< list2<<endl;
}
 