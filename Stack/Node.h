#ifndef D93AF525_87A1_476F_84D1_775124033A83
#define D93AF525_87A1_476F_84D1_775124033A83

class Node{

private:
    int info;
    Node *next;

public:
    Node();
    ~Node();
    int getInfo();
    Node *getNext();
    void setInfo(int valor);
    void setNext(Node *p);

};

#endif /* D93AF525_87A1_476F_84D1_775124033A83 */
/*
Created by João Víctor Costa de Oliveira (StormBreaker1726)
*/