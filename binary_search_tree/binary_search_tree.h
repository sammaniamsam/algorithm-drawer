//====================================================================
// binary_search_tree.h
// Author: sammaniamsam
//====================================================================
#include <iostream>
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

    //private variable
    node *m_pRoot;

    //private functions
    void printAll(node *root);
    //TNode *Search(char *aWord);
    void DestroyTree(node *root);


public:
    binary_search_tree();
    ~binary_search_tree();
    void insert(int key);
    //TNode *RemoveWord(char *aWord);
    //bool ChangeWord(char *aWord, char *eWord);
    //void Translate(char *line);
    void printAll();
};

#endif //BINARY_SEARCH_TREE_BINARYSEARCHTREE_H
