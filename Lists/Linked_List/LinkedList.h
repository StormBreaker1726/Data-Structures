#ifndef E80C9339_B437_4EE6_897B_D76923C91842
#define E80C9339_B437_4EE6_897B_D76923C91842
#include "Node.h"

class LinkedList{

private:
    Node *first;
    Node *last;
    int n;

    void removeNode(Node *p);
    void insert(int val, Node *p);

public:
    LinkedList();
    ~LinkedList();
    bool search(int val);
    void insertInBeginning(int val);
    void removeInBeginning();
    int get(int k);
    void set(int k, int val);

    void insertInEnd(int val);
    void removeEnd();
    void print();
    void printReverse();
    void clean();
    void insertK(int k, int val);
    void removeK(int k);

    void removeOccurrence(int val);
    bool isLike(LinkedList *l2);
    int getSize();
    void removeGreater();
    LinkedList *chain(LinkedList *l2);
    void chainInOne(LinkedList *l2);
    LinkedList *cut(int x);

    void sort();
    void insertSort(int val);
    LinkedList *chainSort(LinkedList *l2);
    int returnIndexValor(int val);

    void randomFull(int sizee);
    Node *getGreater();
    void removeEquals();
};

#endif /* E80C9339_B437_4EE6_897B_D76923C91842 */
/*
Created by João Víctor Costa de Oliveira (StormBreaker 1726)
*/