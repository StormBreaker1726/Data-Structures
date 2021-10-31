#include <iostream>
#include "arrayio.h"
#define TAM 5

using namespace std;

int main(void){

    float vetor[TAM];

    simplearrayrandominitializer(vetor, TAM);
    simplearrayprinter(vetor, TAM);

    return 0;
}
