//====================================================================
// binary_search_tree.h
// Author: sammaniamsam
//====================================================================
#include <iostream>
#include <queue>
//---------------------------------

#ifndef BINARY_SEARCH_TREE_BINARYSEARCHTREE_H
#define BINARY_SEARCH_TREE_BINARYSEARCHTREE_H

//---------------------------------
struct node // the structure for representing tree nodes
{
    int key;
    unsigned char height;
    node* left;
    node* right;
    node(int k) { key = k; left = right = NULL; height = 1; }
};
//---------------------------------

class binary_search_tree
{

private:
    node *m_pRoot; //pointer to root node in BST

    void preorderTraversal(node *root, std::queue<node *> *path);
    void inorderTraversal(node *root, std::queue<node *> *path);
    void postorderTraversal(node *root, std::queue<node *> *path);
    //TNode *Search(char *aWord);
    void DestroyTree(node *root);

public:
    binary_search_tree();
    ~binary_search_tree();
    void insert(int key);
    //TNode *RemoveWord(char *aWord);
    //bool ChangeWord(char *aWord, char *eWord);
    //void Translate(char *line);
    void preorderTraversal(std::queue<node *> *path);
    void inorderTraversal(std::queue<node *> *path);
    void postorderTraversal(std::queue<node *> *path);
};

#endif //BINARY_SEARCH_TREE_BINARYSEARCHTREE_H
