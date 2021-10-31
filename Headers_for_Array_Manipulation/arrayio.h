#ifndef D60E2A5B_A300_4E9D_9E40_896726FC9519
#define D60E2A5B_A300_4E9D_9E40_896726FC9519
/*
Last update: May the 4th 2021
In construct...
*/

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

template <typename T>
void simplearrayinitializer(T *array, int size){
    int i;
    for(i = 0; i < size; i++){
        cout<<"Array["<<i<<"]: ";
        cin>>array[i];
        cout<<endl;
    }
}

template <typename T>
void simplearrayprinter(T *array, int size){
    int i;
    for (size_t i = 0; i < size; i++)
    {
        cout<<"Array["<<i<<"] = "<<array[i]<<endl;
    }
}

template<typename T>
void simplearrayvoid(T *array, int size){
    int i;
    for (size_t i = 0; i < size; i++)
    {
        array[i] = 0;
    }
}

template<typename T>
int simplearraysearcher(T *array, const unsigned int size){
    float key;
    int key_position = -1;
    int i;
    cout<<"What's the key? ";
    cin>>key;

    cout<<endl;
    for (i = 0; i < size; i++)
    {
        if(array[i] == key){
            key_position = i;
            break;
        }
    }

    return key_position;
}

template <typename T>
void simplearrayrandominitializer(T *array, int size){
    int i;
    srand(time(NULL));

    for(i = 0; i < size; i++){
        array[i] = rand() % 100;
    }
}



#endif /* D60E2A5B_A300_4E9D_9E40_896726FC9519 */
/*
Created and maintained by João Víctor Costa de Oliveira (StormBreaker1726)
*/
