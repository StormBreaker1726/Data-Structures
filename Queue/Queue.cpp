#include <iostream>
#include <cstdlib>
#include "Queue.h"

using namespace std;

//FIRST IN FIRST OUT

Queue::Queue(){
    front = back = NULL;
    n = 0;
}

Queue::~Queue(){
    Node *p = front;

    while (front != NULL)
    {
        front = p->getNext();
        delete p;
        p = front;
    }
    n = 0;
}

int Queue::getBegin(){
    if(front != NULL){
        return front->getInfo();
    }
    else{
        cout<<"ERROR! Queue is already empty!"<<endl;
        exit(2);
    }
}

void Queue::push(int val){
    Node *p = new Node();
    p->setInfo(val);
    p->setNext(NULL);

    if(back == NULL){
        front = p;
    }
    else{
        back->setNext(p);
    }
    back = p;
    n++;
}

int Queue::pop(){
    Node *p;
    if(front != NULL){
        p = front;
        front = p->getNext();

        if(front == NULL){
            back = NULL;
        }
        int valor = p->getInfo();
        delete p;
        n--;
        return valor;
    }
    cout<<"ERROR! Queue already empty!"<<endl;
    exit(3);
}

bool Queue::empty(){
    if(n == 0){
        return true;
    }
    else{
        return false;
    }
}

void Queue::print(){
    for(Node *p = front; p != NULL; p = p->getNext()){
        if(p->getNext() != NULL){
            cout<<p->getInfo()<<", ";
        }
        else{
            cout<<p->getInfo()<<endl;
        }
    }
}

void Queue::directionChange(){
    int *vet = new int[size()];
    int j = 0;

    for(Node *p = front; p != NULL; p = p->getNext()){
        vet[size() - j - 1] = p->getInfo();
        j++;
    }
    clean();
    j = 0;

    for(;j < size();){
        push(vet[j]);
        j++;
    }
    delete []vet;
}

int Queue::size(){
    return n;
}

void Queue::clean(){
    int sizee = size();
    for(int j = 0; j < sizee; j++){
        pop();
    }
}

bool Queue::search(int val){
    bool answer = false;
    for(Node *p = front; p != NULL; p = p->getNext()){
        if(p->getInfo() == val){
            answer = true;
            break;
        }
    }
    return answer;
}

/*
Created by João Víctor Costa de Oliveira (StormBreaker 1726)
*/
