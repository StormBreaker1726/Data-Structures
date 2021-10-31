/*
Test file
Created by João Víctor Costa de Oliveira (StormBreaker1726)
*/
#include <iostream>
#include "BinarySearchTree.h"

using namespace std;


void fillSearchTree( BinarySearchTree *a, int p, int q)
{
    // Caso base
    if (p > q) return;

    int meio = (p+q)/2;
    a->insert(meio);
    fillSearchTree (a, p, meio-1);
    fillSearchTree (a, meio+1, q);
}


int main()
{
    BinarySearchTree a;

    fillSearchTree(&a, 10, 35);

    a.inOrder();

    return 0;
}
