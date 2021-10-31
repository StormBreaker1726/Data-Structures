#ifndef DA03524D_DA4E_44A9_B1A8_2C91862D5988
#define DA03524D_DA4E_44A9_B1A8_2C91862D5988

class TreeNode{
private:
    TreeNode *left;
    TreeNode *right;
    int info;

public:
    TreeNode();
    ~TreeNode();

    /*Set functions*/
    void setLeft(TreeNode *p);
    void setInfo(int valor);
    void setRight(TreeNode *p);

    /*Get functions*/
    TreeNode *getLeft();
    int getInfo();
    TreeNode *getRight();

};

#endif /* DA03524D_DA4E_44A9_B1A8_2C91862D5988 */
/*
Created by João Víctor Costa de Oliveira (StormBreaker1726)
*/