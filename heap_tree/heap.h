//====================================================================
// heap.h
// Author: sammaniamsam
//====================================================================
#include <iostream>
//---------------------------------

#ifndef ALGORITHM_DRAWER_HEAP_H
#define ALGORITHM_DRAWER_HEAP_H

//---------------------------------
struct node // the structure for representing tree nodes
{
    int key;
    unsigned char height;
    node* left;
    node* right;
    node(int k) { key = k; left = right = NULL; height = 1; }
};



#endif //ALGORITHM_DRAWER_HEAP_H
