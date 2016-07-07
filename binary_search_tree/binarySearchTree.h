//========================================================================
//Translator.h
//
//Author: Samuel Sikes
//This program is entirely my own work (statement required by UAH CS Dep.)
//========================================================================

#include <iostream>
#include <fstream>
#include <string.h>

#ifndef BINARY_SEARCH_TREE_BINARYSEARCHTREE_H
#define BINARY_SEARCH_TREE_BINARYSEARCHTREE_H

struct TNode
{
    char key[33];
    char EngWord[33];
    TNode *left;
    TNode *right;
};



class Translator
{

private:

    //private variable
    TNode *m_pRoot;

    //private functions
    void PrintAll(TNode *rt);
    TNode *Search(char *aWord);
    void DestroyTree(TNode *rt);


public:
    Translator();
    ~Translator();
    void InsertWord(char *aWord, char *eWord);
    TNode *RemoveWord(char *aWord);
    bool ChangeWord(char *aWord, char *eWord);
    void Translate(char *line);
    void PrintAll();

};
#endif //BINARY_SEARCH_TREE_BINARYSEARCHTREE_H
