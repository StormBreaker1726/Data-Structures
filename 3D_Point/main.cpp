/*
Test file
Created by João Víctor Costa de Oliveira (StormBreaker1726)
*/
#include <iostream>
#include "Point3D.h"

using namespace std;

int main(void){

    Point3D p1(2.5, 9.5, 8);
    Point3D p2(6.5, 8.6, 9);
    Point3D p3(1, 8, 0);

    cout<<boolalpha<<p1.isTriangle(p2, p3)<<endl;

    return 0;
}