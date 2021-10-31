#include "Stack.h"
#include <cmath>
#include <iostream>
#include <stdlib.h>    
#include <time.h>       
using namespace std;

//First in last out

Stack::Stack(){
    top = NULL;
    sizee = 0;
}

Stack::~Stack(){
    Node *p = top;
    while (top != NULL){
        top = p->getNext();
        delete p;
        p = top;
    }
}

int Stack::getTop(){
    if(top != NULL){
        return top->getInfo();
    }
    else{
        cout<<"ERROR! Stack is already empty!"<<endl;
        exit(2);
    }
}

void Stack::pile(int val){
    Node *p = new Node();
    p->setInfo(val);
    p->setNext(top);
    top = p;
    sizee = sizee + 1;
}

int Stack::unpile(){
    Node *p;
    int val;
    if(top != NULL){
        p = top;
        top = p->getNext();
        val = p->getInfo();
        delete p;
        return val;
        sizee = sizee - 1;
    }
    else{
        exit(23);
    }
}

bool Stack::empty(){
    return (top == NULL);
}

void Stack::printFormat(){
    for(Node *p = top; p != NULL; p = p->getNext()){
        cout<<p->getInfo()<<endl;
    }
}

void Stack::print(){
    for(Node *p = top; p != NULL; p = p->getNext()){
        if(p->getNext() != NULL)
            cout<<p->getInfo()<<", ";
        else   
            cout<<p->getInfo()<<endl;
    }
}

int Stack::size(){
    return sizee;
}

void Stack::fillRandom(int siz){
    srand (time(NULL));

    for (int i = 0; i < siz; i++)
    {
        pile(rand() % 100);
    }
}
/*
Created by João Víctor Costa de Oliveira (StormBreaker1726)
*/
