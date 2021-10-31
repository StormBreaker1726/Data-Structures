/*
Teste file
Created by João Víctor Costa de Oliveira (StormBreaker1726)
*/
#include <iostream>
#include "AdjacentList.h"

using namespace std;

int main(void){

    AdjacentList L1(5);

    for (int i = 0; i < 5; i++)
    {
        L1.insertInBeginning(i+1);
    }
    
    L1.print();


    return 0;
}