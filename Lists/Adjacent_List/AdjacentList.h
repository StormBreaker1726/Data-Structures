#ifndef FB357201_C387_43A0_8103_1FE1305BF46F
#define FB357201_C387_43A0_8103_1FE1305BF46F

class AdjacentList{

private:
    int max;
    int n;
    int *vet;

    void reallocate(int newSize);

public:
    AdjacentList(int size);
    ~AdjacentList();

    int get(int k);
    void set(int k, int valor);
    void insertInEnd(int valor);
    void insertK(int k, int valor);
    void insertInBeginning(int valor);
    void removeEnd();
    void removeK(int k);
    void removeBeginning();
    void print();

    int numberNodes();
    int capacity();
    int searchForGreater(int valor);
    void clear();

    int freePositions();

    void insertValor(int vector[], int size);

};

#endif /* FB357201_C387_43A0_8103_1FE1305BF46F */
/*
Created by João Víctor Costa de Oliveira (StormBreaker1726)
*/