#ifndef CB2546B9_FBE1_48C1_8528_A83D59F28FC4
#define CB2546B9_FBE1_48C1_8528_A83D59F28FC4
#include "TreeNode.h"

class BinarySearchTree{
public:
    BinarySearchTree();
    ~BinarySearchTree();

    void insert(int val);
    void remove(int val);
    void print();
    void removeGreater();
    void removeSmaller();
    void inOrder();

    bool empty();
    bool search(int val);

    int greater();
    int least();
    int countEvenPath(int x);

    float mediaPath(int key);

private:
    TreeNode *root;
    TreeNode *auxInsert(TreeNode *p, int val);
    TreeNode *auxRemove(TreeNode *p, int val);
    TreeNode *leastRightSubTree(TreeNode *p);
    TreeNode *greaterLeftSubTree(TreeNode *p);
    TreeNode *removeLeaf(TreeNode *p);
    TreeNode *removeSon(TreeNode *p);
    TreeNode *free(TreeNode *p);
    TreeNode *auxRemoveSmaller(TreeNode *p);

    bool auxSearch(TreeNode *p, int val);

    void printByLevel(TreeNode *p, int level);
    void auxCountEvenPath(TreeNode *p, int x, int *count);
    void auxInOrder(TreeNode *p, int count);
};

#endif /* CB2546B9_FBE1_48C1_8528_A83D59F28FC4 */
/*
Created by João Víctor Costa de Oliveira (StormBreaker1726)
*/