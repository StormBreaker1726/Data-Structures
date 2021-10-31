/*
Test file
*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include "Tree.h"

using namespace std;

int main(void){
/*
No momento que eu indexo uma árvore como sub-árvore não preciso mais da variável q criei para 
ela podendo reutilizar a mesma variável para criar outras árvores
*/

    cout<<fixed;
    Tree *voided = new Tree();
    Tree *a1 = new Tree(), *a2 = new Tree(), *a3 = new Tree(), *a4 = new Tree();

    a1->build(25, voided, voided);
    a2->build(0, voided, voided);
    a3->build(3, a1, a2);

    a1->build(6, voided, voided);
    a2->build(-9, voided, voided);
    a4->build(-8, a1, a2);

    a1->build(4, voided, voided);
    a2->build(18, voided, voided);
    a1->build(22, a1, a2);

    a4->build(15, a4, a1);

    a2->build(2, a4, a3);

    a2->preOrder();
    cout<<endl;
    a2->postOrder();
    cout<<endl;
    a2->inOrder();
    cout<<endl;

    return 0;
}

/*
Created by João Víctor Costa de Oliveira (StormBreaker1726)
*/