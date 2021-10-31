#include <iostream>
#include <cmath>
#include "Point3D.h"

using namespace std;

Point3D::Point3D(float xx, float yy, float zz){
    setX(xx);
    setY(yy);
    setZ(zz);
}

Point3D::~Point3D(){

}

float Point3D::getX(){
    return x;
}

float Point3D::getY(){
    return y;
}

float Point3D::getZ(){
    return z;
}

float Point3D::distance(Point3D p2){
    return sqrt((pow(x - p2.getX(), 2)) + (pow(y - p2.getY(), 2)) + (pow(z - p2.getZ(), 2)));
}

void Point3D::setX(float val){
    x = val;
}

void Point3D::setY(float val){
    y = val;
}

void Point3D::setZ(float val){
    z = val;
}

bool Point3D::isTriangle(Point3D p2, Point3D p3){
    float d1 = distance(p2); //distance p1 to p2
    float d2 = distance(p3); //distance p1 to p3
    float d3 = p3.distance(p2); //distance p3 to p2

    if((pow(d3, 2) > d2 + d1) && (pow(d1, 2) > d3 + d2) && (pow(d2, 2) > d3 + d1)){
        return true;
    }
    else{
        return false;
    }
}

/*
Created by João Víctor Costa de Oliveira (StormBreaker1726)
*/
