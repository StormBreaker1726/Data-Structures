#include <iostream>
#include "Node.h"



Node::Node(){

}

Node::~Node(){

}

void Node::setPrevious(Node *p){
    previous = p;
}

void Node::setNext(Node *p){
    next = p;
}

void Node::setInfo(int val){
    info = val;
}

Node* Node::getPrevious(){
    return previous;
}

Node* Node::getNext(){
    return next;
}

int Node::getInfo(){
    return info;
}

/*
Created by João Víctor Costa de Oliveira (StormBreaker 1726)
*/