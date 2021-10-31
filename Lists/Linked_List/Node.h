#ifndef C66FEE55_55B5_4186_AC6B_3EBE67DF8C07
#define C66FEE55_55B5_4186_AC6B_3EBE67DF8C07

class Node{

private:
    Node *previous;
    Node *next;
    int info;

public:
    Node();
    ~Node();

    void setPrevious(Node *p);
    void setNext(Node *p);
    void setInfo(int val);

    Node *getPrevious();
    Node *getNext();
    int getInfo();
}; 

#endif /* C66FEE55_55B5_4186_AC6B_3EBE67DF8C07 */
/*
Created by João Víctor Costa de Oliveira (StormBreaker 1726)
*/