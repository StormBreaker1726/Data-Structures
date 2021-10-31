#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdlib.h>     
#include <time.h>       
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList(){
    first = last = NULL;
    n = 0;
}

LinkedList::~LinkedList(){
    Node *p = first;
    while (p != NULL){
        Node *t = p->getNext();
        delete p;
        p = t;
    }
}

bool LinkedList::search(int val){
    for(Node *p = first; p != NULL; p = p->getNext()){
        if(p->getInfo() == val){
            return true;
            break;
        }
    }
    return false;
}
void LinkedList::removeNode(Node *p){
    if(p != NULL){
        if(n == 0){
            cout<<"Empty list"<<endl;
            return;
        }
        else if(n == 1){
            first = last = NULL;
        }
        else if(p == first){
            removeInBeginning();
        }
        else if(p == last){
            removeEnd();
        }
        else{
            Node *previous = p->getPrevious();
            Node *next = p->getNext();

            previous->setNext(p->getNext());
            next->setPrevious(p->getPrevious());
            n--;
            delete p;
        }
    }
}

void LinkedList::insert(int val, Node *p){
    if(n != 0){
        Node *q = new Node();
        q->setInfo(val);

        if(p == last){
            q->setNext(NULL);
            p->setNext(q);
            last = q;
        }
        else{
            q->setNext(p->getNext());
            p->setNext(q);
            q->getNext()->setPrevious(q);
        }
        q->setPrevious(p);
        n++;
    }
}

void LinkedList::insertInBeginning(int val){
    Node *p = new Node();

    p->setInfo(val);
    p->setPrevious(NULL);
    p->setNext(first);

    if(n == 0){
        last = p;
    }
    else{
        first->setPrevious(p);
    }
    first = p;
    n++;
}

void LinkedList::removeInBeginning(){
    Node *p;

    if(first != NULL){
        p = first;
        first = p->getNext();
        delete p;
        if(first == NULL){
            last = NULL;
        }
        else{
            first->setPrevious(NULL);
        }
        n--;
    }
    else{
        cout<<"Invalid Operation!!! List already empty!"<<endl;
        exit(3);
    }
}

int LinkedList::get(int k){
    if(first == NULL){
        return -1;
    }
    Node *p = first;
    for(int i = 0; i < k; i++){
        if(p == NULL){
            break;
        }
        p = p->getNext();
    }
    if(p == NULL){
        cout<<"ERROR! Invalid index!"<<endl;
        exit(99);
    }
    else{
        return p->getInfo();
    }
}

void LinkedList::set(int k, int val){
    Node *p = first;

    for(int i = 0; i < k; i++){
        if(p == NULL){
            break;
        }
        p = p->getNext();
    }
    if(p == NULL){
        cout<<"ERROR! Invalid index!"<<endl;
        exit(887);
    }
    else{
        p->setInfo(val);
    }
}

void LinkedList::insertInEnd(int val){
    Node *p = new Node();

    p->setInfo(val);
    p->setNext(NULL);
    p->setPrevious(last);

    if(n == 0){
        first = p;
    }
    else{
        last->setNext(p);
    }

    last = p;

    n++;
}

void LinkedList::removeEnd(){
    Node *p;
    if(last != NULL){
        p = last;
        last = p->getPrevious();
        delete p;

        if(last == NULL){
            first = NULL;
        }
        else{
            last->setNext(NULL);
        }
        n--;
    }
    else{
        cout<<"Invalid Operation! List already empty!"<<endl;
        exit(12);
    }
}

void LinkedList::print(){
    cout<<"[";
    for(Node *p = first; p != NULL; p = p->getNext()){
        cout<<p->getInfo();
        if(p->getNext() != NULL){
            cout<<", ";
        }
    }
    cout<<"]"<<endl;
}

void LinkedList::printReverse(){
    cout<<"[";
    for(Node *p = last; p != NULL; p = p->getPrevious()){
        cout<<p->getInfo();
        if(p->getNext() != NULL){
            cout<<", ";
        }
    }
    cout<<"]"<<endl;
}

void LinkedList::clean(){
    int i = 0;
    for(i = n; i > 0; i--){
        removeEnd();
    }
}

void LinkedList::insertK(int k, int val){
    if(k == 0){
        insertInBeginning(val);
    }
    else if(k == n){
        insertInEnd(val);
    }
    else{
        Node *p = first;
        Node *previous = NULL;
        int i = 0;

        while(i < k && p != NULL){
            i++;
            previous = p;
            p = p->getNext();
        }
        if(p == NULL){
            cout<<"ERROR! Invalid index!"<<endl;
        }
        else{
            Node *neww = new Node();
            neww->setInfo(val);
            neww->setNext(p);
            previous->setNext(neww);
            n++;
        }
    }
}

void LinkedList::removeK(int k){
    if(n == 0){
        cout<<"List is already empty!"<<endl;
    }
    else if(k < n){
        if(k == 0){
            removeInBeginning();
        }
        else if(k == n-1){
            removeInBeginning();
        }
        else{
            Node *p = first;
            Node *previous = NULL;
            int i = 0;

            while(i < k && p != NULL){
                i++;
                previous = p;
                p = p->getNext();
            }
            previous->setNext(p->getNext());
            delete p;
            n--;
        }
    }
    else{
        cout<<"Invalid node!!!\n Finishing program"<<endl;
        exit(342);
    }
}

void LinkedList::removeOccurrence(int val){
    for(Node *p = first; p != NULL; p = p->getNext()){
        if(p->getInfo() == val){
            removeNode(p);
        }
    }
}

bool LinkedList::isLike(LinkedList *l2){
    if(l2->getSize() != getSize()){
        return false;
    }
    else{
        int cont = 0;
        for(Node *p = first; p != NULL; p = p->getNext()){
            if(l2->get(cont) == get(cont)){
                cont++;
            }
            else{
                return false;
                break;
            }
        }
    }
    return true;
}

int LinkedList::getSize(){
    return n;
}

Node *LinkedList::getGreater(){
    Node *greater_k = first;
    for(Node *p = first; p != NULL; p = p->getNext()){
        if(p->getInfo() > greater_k->getInfo()){
            greater_k = p;
        }
    }
    return greater_k;
}

void LinkedList::removeGreater(){
    if(n == 0){
        cout<<"List empty!!!"<<endl;
        exit(9999);
    }
    else{
        removeNode(getGreater());
    }
}

LinkedList *LinkedList::chain(LinkedList *l2){
    LinkedList *l3 = new LinkedList();

    int sizee = l2->getSize() + getSize();

    for(int i = 0; i < getSize(); i++){
        l3->insertInEnd(get(i));
    }
    for(int j = 0; j < l2->getSize(); j++){
        l3->insertInEnd(l2->get(j));
    }
    return l3;
}

void LinkedList::chainInOne(LinkedList *l2){
    for(Node *p = l2->first; p != NULL; p = p->getNext()){
        insertInEnd(p->getInfo());
    }
}

LinkedList *LinkedList::cut(int x){
    LinkedList *neww = new LinkedList();

    Node *p = first;
    Node *previous = NULL;

    int i = 0;

    while(i < x && p != NULL){
        i++;
        previous = p;
        p = p->getNext();
    }
    if(p == NULL){
        cout<<"ERROR! Invalid index!!!"<<endl;
    }
    else if(previous == NULL){
        neww->first = first;
        neww->last = last;

        neww->n = n;
        first = last = NULL;
        n = 0;
    }
    else{
        neww->first = p;
        neww->last = last;
        neww->n = n - x;
        last = previous;
        n = x;
        last->setNext(NULL);
    }
    return neww;
}
void LinkedList::sort(){
    int aux;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(get(i) < get(j)){
                aux = get(i);
                set(i, get(j));
                set(j, aux);
            }
        }
    }
}

void LinkedList::insertSort(int val){
    Node *p = first;
    int i = 0;
    while(p != NULL && p->getInfo() < val){
        i++;
        p = p->getNext();
    }
    insertK(i, val);
}

LinkedList *LinkedList::chainSort(LinkedList *l2){
    LinkedList *lnew = new LinkedList();

    int sizee = getSize() + l2->getSize();

    for(int i = 0; i < getSize(); i++){
        lnew->insertSort(get(i));
    }
    for(int j = 0; j < l2->getSize(); j++){
        lnew->insertSort(l2->get(j));
    }
    return lnew;
}


int LinkedList::returnIndexValor(int val){
    int j = 0;

    for(Node *p = first; p != NULL; p = p->getNext()){
        if(p->getInfo() == val){
            return j;
            break;
        }
        j++;
    }
    return -1;
}

void LinkedList::randomFull(int sizee){
    if(n != 0){

        n = sizee;

        for (int i = 0; i < n; i++)
        {
            srand (time(NULL));
            insertSort(rand()%100);
        }
    }    
    else{
        cout<<"You can only use this function if the list is empty"<<endl;
        exit(123);
    }
}

void LinkedList::removeEquals(){
    int sizee = getSize();
    sort();
    for (Node *p = first; p != NULL; p = p->getNext()){
        Node *z = p->getNext(); 
        if(p->getInfo() == z->getInfo()){
            removeNode(z);
        }
    }
}

/*
Created by João Víctor Costa de Oliveira (StormBreaker 1726)
*/
