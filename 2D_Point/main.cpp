/*
Test file
Created by João Víctor Costa de Oliveira (StormBreaker1726)
*/
#include <iostream>
#include "Point2D.h"

using namespace std;

int main(void){

    Point2D p1(2.5, 9.5);
    Point2D p2(6.5, 8.6);
    Point2D p3(1, 8);

    cout<<boolalpha<<p1.isTriangle(p2, p3)<<endl;

    return 0;
}