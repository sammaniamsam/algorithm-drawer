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

void min_heap::topDown (unsigned long position) {

    //root
    if (position == 1) return;
    //not root
    else {
        //child < parent
        if(this->minHeapVector->at(position-1)->key < this->minHeapVector->at((position/2)-1)->key) {
            //swap child, parent keys
            int tempKey = this->minHeapVector->at(position-1)->key;
            this->minHeapVector->at(position-1)->key = this->minHeapVector->at((position/2)-1)->key;
            this->minHeapVector->at((position/2)-1)->key = tempKey;
            //compare parent w/ new key
            topDown(position/2);
        }
        //child > parent
        else {
            return;
        }
    }
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

    this->minHeapVector->push_back(newNode);

    this->topDown(minHeapVector->size());
}

