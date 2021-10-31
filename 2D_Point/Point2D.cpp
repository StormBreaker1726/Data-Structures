#include <iostream>
#include <cmath>
#include "Point2D.h"

using namespace std;

Point2D::Point2D(float xx, float yy){
    setX(xx);
    setY(yy);
}

Point2D::~Point2D(){

}

float Point2D::getX(){
    return x;
}

float Point2D::getY(){
    return y; 
}

float Point2D::distance(Point2D p2){
    return sqrt((pow(x - p2.getX(), 2)) + (pow(y - p2.getY(), 2)));
}

void Point2D::setX(float val){
    x = val;
}

void Point2D::setY(float val){
    y = val;
}

bool Point2D::isTriangle(Point2D p2, Point2D p3){
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