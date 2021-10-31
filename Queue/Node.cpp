#include "Node.h"
#include <iostream>

using namespace std;

Node::Node(){}

Node::~Node(){}

int Node::getInfo(){
    return info;
}

Node* Node::getNext(){
    return next;
}

void Node::setInfo(int valor){
    info = valor;
}

void Node::setNext(Node *p){
    next = p;
}
/*
Created by João Víctor Costa de Oliveira (StormBreaker1726)
*/