#ifndef B2C73EED_3278_45F7_A2FA_E3CDD8CE6E95
#define B2C73EED_3278_45F7_A2FA_E3CDD8CE6E95
#include "Node.h"

class Queue{

private:
    Node *front;
    Node *back;
    int n;

public:
    Queue();
    ~Queue();
    int getBegin();
    void push(int val);
    int pop();
    bool empty();
    void print();

    void directionChange();
    int size();
    void clean();
    bool search(int val);

};

#endif /* B2C73EED_3278_45F7_A2FA_E3CDD8CE6E95 */
/*
Created by João Víctor Costa de Oliveira (StormBreaker 1726)
*/
