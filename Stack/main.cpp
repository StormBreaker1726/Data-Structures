/*
Test file
Created by João Víctor Costa de Oliveira (StormBreaker1726)
*/
#include "Stack.h"
#include <cmath>
#include <iostream>

using namespace std;

int main(void){
    Stack s1;

    int size = 9;

    s1.fillRandom(size);

    s1.printFormat();

    s1.print();

    cout<<s1.size()<<endl;

    return 0;
}
