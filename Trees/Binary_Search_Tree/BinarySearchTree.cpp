#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

BinarySearchTree::BinarySearchTree(){
    root = NULL;
}

BinarySearchTree::~BinarySearchTree(){
    root = free(root);
}

void BinarySearchTree::insert(int val){
    root = auxInsert(root, val);
}

void BinarySearchTree::remove(int val){
    root = auxRemove(root, val);
}

void BinarySearchTree::print(){
    printByLevel(root, 0);
}

void BinarySearchTree::removeGreater(){
    remove(greater());
}

void BinarySearchTree::removeSmaller(){
    root = auxRemoveSmaller(root);
}

void BinarySearchTree::inOrder(){
    auxInOrder(root, 0);
    cout<<endl;
}

bool BinarySearchTree::empty(){
    if(root == NULL) 
        return true;
    else
        return false;
}

bool BinarySearchTree::search(int val){
    return auxSearch(root, val);
}

int BinarySearchTree::greater(){
    if(root == NULL){
        cout<<"Empty tree!"<<endl;
        return -1;
    }
    TreeNode *p = root;
    while(p->getRight() != NULL){
        p = p->getRight();
    }
    return p->getInfo();
}

int BinarySearchTree::least(){
    if(root != NULL){
        TreeNode *p;
        for(p = root; p->getLeft() != NULL; p = p->getLeft());
        return p->getInfo();
    }
    else{
        cout<<"Empty tree!"<<endl;
        return -1;
    }
}

int BinarySearchTree::countEvenPath(int x){
    int controller = 0;
    auxCountEvenPath(root, x, &controller);
    return controller;
}

float BinarySearchTree::mediaPath(int key){
    int sum = 0, count = 0;
    TreeNode *p = root;
    while(p != NULL){
        count++;
        sum += p->getInfo();

        if(key == p->getInfo()){
            break;
        }
        else if( key > p->getInfo()){
            p = p->getRight();
        }
        else{
            p = p->getLeft();
        }
    }
    return (float)sum/count;
}

TreeNode *BinarySearchTree::auxInsert(TreeNode *p, int val){
    if(p == NULL){
        p = new TreeNode();
        p->setInfo(val);
        p->setLeft(NULL);
        p->setRight(NULL);
    }
    else if(val < p->getInfo()){
        TreeNode *son = auxInsert(p->getLeft(), val);
        p->setLeft(son);
    }
    else{
        TreeNode *son = auxInsert(p->getRight(), val);
        p->setRight(son);
    }
    return p;
}

TreeNode *BinarySearchTree::auxRemove(TreeNode *p, int val){
    if(p == NULL){
        return NULL;
    }
    else if(val < p->getInfo()){
        p->setLeft(auxRemove(p->getLeft(), val));
    }
    else if(val > p->getInfo()){
        p->setRight(auxRemove(p->getRight(), val));
    }
    else{
        if(p->getLeft() == NULL && p->getRight() == NULL){
            p = removeLeaf(p);
        }
        else if((p->getLeft() == NULL) || (p->getRight() == NULL)){
            p = removeSon(p);
        }
        else{
            TreeNode *aux = greaterLeftSubTree(p);
            int tmp = aux->getInfo();
            p->setInfo(tmp);
            aux->setInfo(val);
            p->setLeft(auxRemove(p->getLeft(), val));
        }
    }
    return p;
}

TreeNode *BinarySearchTree::leastRightSubTree(TreeNode *p){
    TreeNode *aux = p->getRight();
    while(aux->getLeft() != NULL){
        aux = aux->getLeft();
    }
    return aux;
}

TreeNode *BinarySearchTree::greaterLeftSubTree(TreeNode *p){
    TreeNode *aux = p->getLeft();
    while(aux->getRight() != NULL){
        aux = aux->getRight();
    }
    return aux;
}

TreeNode *BinarySearchTree::removeLeaf(TreeNode *p){
    delete p;
    return NULL;
}

TreeNode *BinarySearchTree::removeSon(TreeNode *p){
    TreeNode *aux;
    if(p->getLeft() == NULL){
        aux = p->getRight();
    }
    else{
        aux = p->getLeft();
    }
    delete p;
    return aux;
}

TreeNode *BinarySearchTree::free(TreeNode *p){
    if(p != NULL){
        p->setLeft(free(p->getLeft()));
        p->setRight(free(p->getRight()));

        delete p;
        p = NULL;
    }
    return p;
}

TreeNode *BinarySearchTree::auxRemoveSmaller(TreeNode *p){
    if(p == NULL){
        return NULL;
    }
    else if(p->getLeft() != NULL){
        TreeNode *son = auxRemoveSmaller(p->getLeft());
        p->setLeft(son);
    }
    else{
        if(p->getRight() != NULL){
            p = removeSon(p);
        }
        else{
            p = removeLeaf(p);
        }
    }
    return p;
}

bool BinarySearchTree::auxSearch(TreeNode *p, int val){
    if(p == NULL){
        return false;
    }
    else if(p->getInfo() == val){
        return true;
    }
    else if(val < p->getInfo()){
        return auxSearch(p->getLeft(), val);
    }
    else{
        return auxSearch(p->getRight(), val);
    }
}

void BinarySearchTree::printByLevel(TreeNode *p, int level){
    if(p != NULL){
        cout<<"("<<level<<")";
        for(int i = 0; i <= level; i++){
            cout<<"--";
        }
        cout<<p->getInfo()<<endl;
        printByLevel(p->getLeft(), level + 1);
        printByLevel(p->getRight(), level + 1);
    }
}

void BinarySearchTree::auxCountEvenPath(TreeNode *p, int x, int *count){
    if(p == NULL){
        return;
    }
    else{
        if(p->getInfo() % 2 == 0){
            *count = *count + 1;
        }
        if(p->getInfo() == x){
            return;
        }
        else if(x < p->getInfo()){
            auxCountEvenPath(p->getLeft(), x, count);
        }
        else{
            auxCountEvenPath(p->getRight(), x, count);
        }
    }
}

void BinarySearchTree::auxInOrder(TreeNode *p, int count){
    if(p != NULL){
        auxInOrder(p->getLeft(), count + 1);
        for (int i = 0; i < count; i++){
            cout<<"\t";
        }
        cout<<p->getInfo()<<endl;
        auxInOrder(p->getRight(), count + 1);
    }
}

/*
Created by João Víctor Costa de Oliveira (StormBreaker1726)
*/