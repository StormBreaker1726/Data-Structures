#ifndef DB40BAC9_BC61_4E3E_99FC_0943CFF816B6
#define DB40BAC9_BC61_4E3E_99FC_0943CFF816B6
#include "TreeNode.h"

class Tree{
public:
    Tree();
    ~Tree();
    int getRoot();
    void build(int x, Tree *stl, Tree *str);
    void nullRoot();
    bool voided();
    bool search(int x);
    void preOrder();
    void buildTree();
    void insert(int x);
    void postOrder();
    void inOrder();
    int numNodes();
    int height();
    int countNodeLeaf();
    void printLevel(int k);
    float mediaLevel(int k);
    int min();
    int max();
    bool isFull();
    float mediaTree();
    void elegantCount();


private:
    TreeNode *root;
    TreeNode* release(TreeNode *p);
    TreeNode* auxBuildTree();
    TreeNode* auxInsert(TreeNode *p, int x);

    bool auxSearch(TreeNode *p, int x);
    void auxPreOrder(TreeNode *p, int count);
    void auxPrintLevel(TreeNode *p, int actual, int k);
    void auxReverse(TreeNode *p);

    int countSons(TreeNode *p);
    int countNodes(TreeNode *p, int *count, int k);
    void disjoin();
    void auxPostOrder(TreeNode *p);

    void auxInOrder(TreeNode *p);
    void auxNumNodes(TreeNode *p, int *count);
    int auxHeight(TreeNode *p);
    void auxCountPreOrder(TreeNode *p, int *oddNode, int *node2Sons);

    int auxCountNodeLeaf(TreeNode *p);
    void auxPrintLevel(TreeNode *p, int k);
    float auxSum(TreeNode *p, int k);
    void auxMin(TreeNode *p, int *min);
    void auxMax(TreeNode *p, int *max);

    void auxMediaTree(TreeNode *p, int *count, int *sum);
    void auxMediaLevel(TreeNode *p, int *count, int *sum, int k);
    void auxElegantCount(TreeNode *p, int *count, int *sum);

};

#endif /* DB40BAC9_BC61_4E3E_99FC_0943CFF816B6 */
/*
Created by João Víctor Costa de Oliveira (StormBreaker1726)
*/