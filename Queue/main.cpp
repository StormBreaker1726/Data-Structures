/*
Test file
Created by João Víctor Costa de Oliveira
*/

#include <iostream>
#include <cmath>
#include "Queue.h"

using namespace std;


int main(void){

    int tam = 5;
    Queue f;
    Queue f2;
    srand(time(NULL));
    for (int i = 0; i < tam; i++)
    {
        f.push(rand()%50);
    }

    for (int i = 0; i < tam; i++)
    {
        f2.push(rand()%50);
    }

    f.print();
    f2.print();

    return 0;
}