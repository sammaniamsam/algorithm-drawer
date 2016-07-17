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
    //if(2 children)
        //if(parent > right OR parent > left)
            //if(parent > right AND parent > left)
                //if(left > right)
                    //swap right and parent
                //else
                    //swap left and parent
            //else if(parent > left)
                //swap left and parent
            //else
                //swap right and parent
    //else (one child)
        //if(parent > left)
            //swap left and parent
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

