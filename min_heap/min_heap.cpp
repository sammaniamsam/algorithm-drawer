//====================================================================
// min_heap.cpp
// Author: sammaniamsam
//====================================================================
#include "min_heap.h"
//---------------------------------

//---------------------------------
//---------------------------------
//--------PRIVATE METHODS----------
//---------------------------------
//---------------------------------

void min_heap::buildBottomUp (node* rootNode, node* newNode) {

    //newNode is root (put this case last)
    if((rootNode == NULL) && (rootNode->height == 1)){
        this->m_pRoot = newNode;
        return;
    }
    //node has no children
    else if(this->m_pRoot->right != NULL) {

    }
    //node has left & right children
    else if((this->m_pRoot->left != NULL) && (this->m_pRoot->right != NULL)) {

    }
    //node has left child
    else if(this->m_pRoot->right != NULL) {

    }
    //re-heap
}

//---------------------------------
//---------------------------------
//--------PUBLIC METHODS-----------
//---------------------------------
//---------------------------------

min_heap::min_heap() {
    this->m_pRoot = NULL;
}

void min_heap::insert(int& key) {
    node* newNode;
    newNode = new node(key);
    buildBottomUp(this->m_pRoot, newNode);
}

