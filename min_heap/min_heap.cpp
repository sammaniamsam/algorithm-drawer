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

//---------------------------------
//FUNCTION:
//PURPOSE:
//---------------------------------
void min_heap::topDown(unsigned long position) {

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
            this->topDown(position/2);
        }
        //child > parent
        else return;
    }
}

//---------------------------------
//FUNCTION:
//PURPOSE:
//---------------------------------
void min_heap::defineNodePtrs(unsigned long position) {

    //root
    if (position == 1) return;
    //not root
    else {
        //left child
        if(position % 2 == 0) {
            this->minHeapVector->at((position/2)-1)->left = this->minHeapVector->at(position-1);
        }
        //right child
        else {
            this->minHeapVector->at((position/2)-1)->right = this->minHeapVector->at(position-1);
        }
        //connect next child to parent
        this->defineNodePtrs(position-1);
    }
}

//---------------------------------
//---------------------------------
//--------PUBLIC METHODS-----------
//---------------------------------
//---------------------------------

//---------------------------------
//FUNCTION:
//PURPOSE:
//---------------------------------
min_heap::min_heap() {

    this->minHeapVector = new std::vector<node *>;
}

//---------------------------------
//FUNCTION:
//PURPOSE:
//---------------------------------

//DESTRUCTOR FUNCTION IS NOT CORRECT
//NEEDS TO SET EACH HEAP NODES' PTRS
//TO NULL
min_heap::~min_heap() {

    node* nPtr;
    while(!this->minHeapVector->empty()) {
        nPtr = this->minHeapVector->back();
        delete nPtr; nPtr = NULL;
        this->minHeapVector->pop_back();
    }
    delete this->minHeapVector; this->minHeapVector = NULL;
}

//---------------------------------
//FUNCTION:
//PURPOSE:
//---------------------------------
void min_heap::insert(int& key) {

    node* newNode;
    newNode = new node(key);
    this->minHeapVector->push_back(newNode);
    //heapify using top down
    this->topDown(this->minHeapVector->size());
    //define heap nodes' ptrs
    this->defineNodePtrs(this->minHeapVector->size());
}

//---------------------------------
//FUNCTION:
//PURPOSE:
//---------------------------------
bool min_heap::search(int& key, std::queue<node *> *path) {

    //declare variables
    unsigned long i = 0;
    std::vector<node *>::iterator it;

    //search for key
    for(it = this->minHeapVector->begin(); it != this->minHeapVector->end(); ++it, i++) {
        //record search path
        path->push(this->minHeapVector->at(i));
        //key found
        if(this->minHeapVector->at(i)->key == key) return true;
    }
    //key not found
    return false;
}

