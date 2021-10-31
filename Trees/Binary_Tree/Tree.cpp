#include <cmath>
#include <iostream>
#include <iomanip>
#include "Tree.h"

using namespace std;

Tree::Tree(){
    root = NULL;
}

Tree::~Tree(){
    root = release(root);
}

int Tree::getRoot(){
    if(root != NULL){
        return root->getInfo();
    }
    else{
        cout<<"Empty Tree!"<<endl;
        exit(1);
    }
}

void Tree::build(int x, Tree *stl, Tree *str){
    TreeNode *p = new TreeNode();
    p->setInfo(x);
    p->setLeft(stl->root);
    p->setRight(str->root);
    root = p;
}

void Tree::nullRoot(){
    root = NULL;
}

bool Tree::voided(){
    return (root == NULL);
}

bool Tree::search(int x){
    return auxSearch(root, x);
}

void Tree::preOrder(){
    cout<<"Tree (Pre Order):"<<endl;
    auxPreOrder(root, 0);
    cout<<endl;
}

void Tree::buildTree(){
    if(!voided()){
        cout<<"It's not possible to remount this tree... but you can insert new nodes."<<endl;
    }
    else{
        cout<<"Tree build (Pre Order): "<<endl;
        root = auxBuildTree();
    }
}

void Tree::insert(int x){
    root = auxInsert(root, x);
}

void Tree::postOrder(){
    cout<<"Tree (Post Order):"<<endl;
    auxPostOrder(root);
    cout<<endl;
}

void Tree::inOrder(){
    cout<<"Tree (In Order):"<<endl;
    auxInOrder(root);
    cout<<endl;
}

int Tree::numNodes(){
    int count = 0;
    auxNumNodes(root, &count);
    return count;
}

int Tree::height(){
    return auxHeight(root);
}

int Tree::countNodeLeaf(){
    return auxCountNodeLeaf(root);
}

void Tree::printLevel(int k){
    cout<<"Level "<<k<<" of the tree:"<<endl;
    disjoin();
    auxPrintLevel(root, k);
    disjoin();
    cout<<endl;
}

float Tree::mediaLevel(int k){
    int count = 0;
    int sum = 0;

    auxMediaLevel(root, &count, &sum, k);
    return ((float)sum)/((float)count);
}

int Tree::min(){
    int min = root->getInfo();
    auxMin(root, &min);
    return min;
}

int Tree::max(){
    int max = root->getInfo();
    auxMax(root, &max);
    return max;
}

bool Tree::isFull(){
    int number_of_nodes = numNodes();
    int h = height();

    //using the mathematical formula n = 2^(h+1) - 1
    if(number_of_nodes == (pow(2, (h+1))-1)){
        return true;
    }
    else{
        return false;
    }
}

float Tree::mediaTree(){
    int count = 0;
    int sum = 0;
    auxMediaTree(root, &count, &sum);

    return ((float)sum/(float)count);
}

void Tree::elegantCount(){
    int sum, count;
    sum = count = 0;
    if(root->getRight() == NULL && root->getLeft() == NULL){
        sum = root->getInfo();
        count = 0;
    }
    else{
        auxElegantCount(root, &count, &sum);
    }
    cout<<"Number of non-leaf nodes: "<<count<<endl;
    cout<<"Sum of leaf nodes: "<<sum<<endl;
}

TreeNode* Tree::release(TreeNode *p){
    if(p != NULL){
        p->setLeft(release(p->getLeft()));
        p->setRight(release(p->getRight()));
        delete p;
        p = NULL;
    }
    return NULL;
}

TreeNode* Tree::auxBuildTree(){
    string Lin;
    cout<<"Valor: ";
    cin>>Lin;

    if(Lin != "NULL" && Lin != "null"){
        istringstream ent(Lin);
        int valor;

        ent>>valor;
        TreeNode *p = new TreeNode();
        p->setInfo(valor);

        cout<<"Left: "<<endl;
        p->setLeft(auxBuildTree());
        cout<<"Back in node..."<<p->getInfo()<<endl;

        cout<<"Right: "<<endl;
        p->setRight(auxBuildTree());
        cout<<"Back in node..."<<p->getInfo()<<endl;

        return p;
    }
    else{
        return NULL;
    }
}

TreeNode* Tree::auxInsert(TreeNode *p, int x){
    if(p == NULL){
        p = new TreeNode();
        p->setInfo(x);
        p->setLeft(NULL);
        p->setRight(NULL);
    }
    else{
        char direction;
        cout<<x<<" to the left (l) or to the right (r) of "<<p->getInfo()<<": ";
        cin>>direction;

        if(direction == 'e' || direction == 'E'){
            p->setLeft(auxInsert(p->getLeft(), x));
        }
        else{
            p->setRight(auxInsert(p->getRight(), x));
        }
    }
    return p;
}

bool Tree::auxSearch(TreeNode *p, int x){
    if(p == NULL){
        return false;
    }
    else if(p->getInfo() == x){
        return true;
    }
    else if(auxSearch(p->getLeft(), x)){
        return true;
    }
    else{
        return auxSearch(p->getRight(), x);
    }
}

void Tree::auxPreOrder(TreeNode *p, int count){
    if(p != NULL){
        for (int i = 0; i < count; i++)
        {
            cout<<"\t";
        }
        cout<<p->getInfo()<<endl;
        auxPreOrder(p->getLeft(), count+1);
        auxPreOrder(p->getRight(), count+1);
    }
}

void Tree::auxPrintLevel(TreeNode *p, int actual, int k){
    if(p != NULL){
        if(k == 0){
            cout<<p->getInfo()<<"  ";
        }
        else{
            auxPrintLevel(p->getLeft(), k-1);
            auxPrintLevel(p->getRight(), k-1);
        }
    }
}

int Tree::countSons(TreeNode *p){
    if(p != NULL){
        if(p->getLeft() == NULL && p->getRight() == NULL){
            return 0;
        }
        else if(p->getLeft() != NULL && p->getRight() != NULL){
            return 2;
        }
        else{
            return 1;
        }
    }
    return -1;
}

int Tree::countNodes(TreeNode *p, int *count, int k){
    if(p == NULL){
        return 0;
    }
    if(k == 0){
        *count = *count + 1;
    }
    else{
        countNodes(p->getLeft(), count, k-1);
        countNodes(p->getRight(), count, k-1);
    }
    return 0;
}

void Tree::disjoin(){
    cout<<endl;
    for (int i = 0; i < 30; i++)
    {
        cout<<"-";
    }
    cout<<endl;
    
}

void Tree::auxPostOrder(TreeNode *p){
    if(p != NULL){
        auxPostOrder(p->getLeft());
        auxPostOrder(p->getRight());
        cout<<p->getInfo()<< "  ";
    }
}

void Tree::auxInOrder(TreeNode *p){
    if(p != NULL){
        auxInOrder(p->getLeft());
        cout<<p->getInfo()<<"  ";
        auxInOrder(p->getRight());
    }
}

void Tree::auxNumNodes(TreeNode *p, int *count){
    if(p != NULL){
        *count = *count + 1;
        auxNumNodes(p->getLeft(), count);
        auxNumNodes(p->getRight(), count);
    }
}

int Tree::auxHeight(TreeNode *p){
    if(p == NULL){
        return -1;
    }
    int hl = auxHeight(p->getLeft());
    int hr = auxHeight(p->getRight());

    return 1 + (hl > hr ? hl : hr);
}

void Tree::auxCountPreOrder(TreeNode *p, int *oddNode, int *node2Sons){
    if(p != NULL){
        if((abs(p->getInfo())) % 2 != 0){
            *oddNode = *oddNode + 1;
        }
        if(p->getLeft() != NULL && p->getRight() != NULL){
            *node2Sons = *node2Sons + 1;
        }
        auxCountPreOrder(p->getLeft(), oddNode, node2Sons);
        auxCountPreOrder(p->getRight(), oddNode, node2Sons);
    }
}

int Tree::auxCountNodeLeaf(TreeNode *p){
    if(p == NULL){ //void tree
        return 0;
    }
    else if(p->getLeft() == NULL && p->getRight() == NULL){ //all nodes are leaves
        return 1;
    }
    else{//only one node is leaf
        return auxCountNodeLeaf(p->getLeft()) + auxCountNodeLeaf(p->getRight());
    }
}

void Tree::auxPrintLevel(TreeNode *p, int k){
    if(p != NULL){
        if(k == 0){
            cout<<p->getInfo()<<"  ";
        }
        else{
            auxPrintLevel(p->getLeft(), k-1);
            auxPrintLevel(p->getRight(), k-1);
        }
    }
}

float Tree::auxSum(TreeNode *p, int k){
    if(p == NULL){
        return 0;
    }
    else if(k == 0){
        return p->getInfo();
    }
    else{
        return auxSum(p->getLeft(), k-1) + auxSum(p->getRight(), k-1);
    }
}

void Tree::auxMin(TreeNode *p, int *min){
    if(p != NULL){
        if(p->getInfo() < *min){
            int info = p->getInfo();
            *min = info;
        }
        auxMin(p->getLeft(), min);
        auxMin(p->getRight(), min);
    }
}

void Tree::auxMax(TreeNode *p, int *max){
    if(p != NULL){
        if(p->getInfo() > *max){
            int info = p->getInfo();
            *max = info;
        }
        auxMax(p->getLeft(), max);
        auxMax(p->getRight(), max);
    }
}

void Tree::auxMediaTree(TreeNode *p, int *count, int *sum){
    if(p != NULL){
        *sum = *sum + p->getInfo();
        *count = *count + 1;
        auxMediaTree(p->getLeft(), count, sum);
        auxMediaTree(p->getRight(), count, sum);
    }
}

void Tree::auxMediaLevel(TreeNode *p, int *count, int *sum, int k){
    if(p != NULL){
        if(k == 0){
            *sum = *sum + p->getInfo();
            (*count)++;
        }
        else{
            auxMediaLevel(p->getLeft(), count, sum, k-1);
            auxMediaLevel(p->getRight(), count, sum, k-1);
        }
    }
}

void Tree::auxElegantCount(TreeNode *p, int *count, int *sum){
    if(p != NULL){
        auxElegantCount(p->getLeft(), count, sum);
        if(countSons(p) != 0){
            *count = *count + 1;
        }
        else{
            *sum = *sum + p->getInfo();
        }
        auxElegantCount(p->getRight(), count, sum);
    }
}

/*
Created by João Víctor Costa de Oliveira (StormBreaker1726)
*/