#include "TreeNode.h"
#include <iostream>

using namespace std;

TreeNode::TreeNode(){

}

TreeNode::~TreeNode(){

}

void TreeNode::setLeft(TreeNode *p){
    left = p;
}

void TreeNode::setInfo(int valor){
    info = valor;
}

void TreeNode::setRight(TreeNode *p){
    right = p;
}

TreeNode* TreeNode::getLeft(){
    return left;
}

TreeNode* TreeNode::getRight(){
    return right;
}

int TreeNode::getInfo(){
    return info;
}
/*
Created by João Víctor Costa de Oliveira (StormBreaker1726)
*/