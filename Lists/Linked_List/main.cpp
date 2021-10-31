/*
Test file
Created by João Víctor Costa de Oliveira (StormBreaker 1726)
*/


#include <iostream>
#include <cmath>
#include "LinkedList.h"

#define TAM 10

using namespace std;

int main(void){

    LinkedList l;

    for (int i = 0; i < TAM; i++)
    {
        l.insertInEnd(i);
    }
    for (int i = 0; i < TAM; i++)
    {
        l.insertInEnd(i);
    }


    cout<<"Original: ";
    l.print();

    l.removeEquals();

    cout<<"New: ";
    l.print();

    return 0;
}