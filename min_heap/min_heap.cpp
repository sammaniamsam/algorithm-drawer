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

void min_heap::buildBottomUp (std::queue<node *>* mhQueue) {

    mhQueue[mhQueue->size()/2];
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

    this->minHeapQueue->push(newNode);

    this->buildBottomUp(this->minHeapQueue);
}

