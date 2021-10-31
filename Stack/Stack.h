#ifndef D61A0473_6D81_49D2_92C5_61D58941F248
#define D61A0473_6D81_49D2_92C5_61D58941F248
#include "Node.h"

class Stack{

private:
    Node *top;
    int sizee;

public:
    Stack();
    ~Stack();
    int getTop();
    void pile(int val);
    int unpile();
    bool empty();
    void printFormat();
    void print();
    int size();
    void fillRandom(int siz);

};

#endif /* D61A0473_6D81_49D2_92C5_61D58941F248 */
/*
Created by João Víctor Costa de Oliveira (StormBreaker1726)
*/
