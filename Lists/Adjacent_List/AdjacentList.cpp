#include "AdjacentList.h"
#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

AdjacentList::AdjacentList(int size){
    max = size;
    n = 0;
    vet = new int[max];
}

AdjacentList::~AdjacentList(){
    delete []vet;
}

int AdjacentList::get(int k){
    if(k>=0 && k < n){
        return vet[k];
    }
    else{
        cout<<"ERROR! This index is invalid."<<endl;
        exit(1);
    }
}

void AdjacentList::set(int k, int valor){
    if(k >= 0 && k < n){
        vet[k] = valor;
    }
    else{
        cout<<"ERROR! This index is invalid."<<endl;;
        exit(1);
    }
}


void AdjacentList::insertInEnd(int valor){
    if(n == max){
        reallocate(2 * max);
    }
    vet[n] = valor;
    n = n + 1;
}
void AdjacentList::insertK(int k, int valor){
    if(n == max){
        cout<<"ERROR! This index is invalid."<<endl;
        exit(3);
    }
    if(k >= 0 && k < n){
        for (int i = n-1; i >= k; i--)
        {
            vet[i+1] = vet[i];
        }
        vet[k] = valor;
        n = n + 1;
    }
    else{
        cout<<"ERROR! This index is invalid."<<endl;
        exit(8);
    }
}

void AdjacentList::insertInBeginning(int valor){
    if(n == 0){
        vet[n] = valor;
        n = n + 1;
    }
    else{
        insertK(0, valor);
    }
}

void AdjacentList::removeEnd(){
    if(n == 0){
        cout<<"ERROR! The list is already empty!"<<endl;
        exit(587);
    }
    n = n - 1;
}

void AdjacentList::removeK(int k){
    if(k >= 0 && k < n){
        for(int i = 0; i < n-1; i++){
            vet[i] = vet[i+1];
        }
        n = n - 1;
    }
    else{
        cout<<"ERROR! Invalid index!"<<endl;
        exit(88);
    }
}

void AdjacentList::removeBeginning(){
    removeK(0);
}

void AdjacentList::print(){
    for(int i = 0; i < n; i++){
        if(i != n-1)
            cout<<get(i)<< ", ";
        else
            cout<<get(i)<<endl;
    }
}

int AdjacentList::numberNodes(){
    return n;
}

int AdjacentList::capacity(){
    return max;
}

int AdjacentList::searchForGreater(int valor){
    int answer = -1;
    for(int i = 0; i < n; i++){
        if(vet[i] > valor){
            answer = i;
            break;
        }
    }
    return answer;
}

void AdjacentList::clear(){
    n = 0;
}

void AdjacentList::insertValor(int vector[], int size){
    if(freePositions() < size){
        reallocate(max + size - freePositions());
    }
    for(int i = 0; i < size; i++){
        insertInEnd(vector[i]);
    }
}

void AdjacentList::reallocate(int newSize){
    if(newSize > n){
        int *newVector = new int[newSize];

        for(int i = 0; i < n; i++){
            newVector[i] = vet[i];
        }
        delete []vet;

        vet = newVector;
        max = newSize;
    }
    else{
        cout<<"ERROR! Invalid new size!"<<endl;
        exit(87);
    }
}

int AdjacentList::freePositions(){
    return (max - n);
}

/*
Created by João Víctor Costa de Oliveira (StormBreaker1726)
*/