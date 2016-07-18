//====================================================================
// min_heap.h
// Author: sammaniamsam
//====================================================================
#include <iostream>
#include <vector>
#include <queue>
//---------------------------------

#ifndef ALGORITHM_DRAWER_MIN_HEAP_H
#define ALGORITHM_DRAWER_MIN_HEAP_H

//---------------------------------
struct node // the structure for representing tree nodes
{
    int key;
    unsigned int height;
    node* left;
    node* right;
    node(int k) { key = k; left = right = NULL; height = 1; }
};
//---------------------------------

class min_heap
{
    private:
        std::vector<node *>* minHeapVector; //ptr to min heap

        void topDown (unsigned long position);
        void defineNodePtrs(unsigned long position);
        void setPtrsNull();

    public:
        min_heap();
        ~min_heap();
        void insert(int& key);
        bool search(int& key, std::queue<node *> *path);
        bool removeNode();
//delete()
//clear()
//breadthFirstSearch()
//deapthFirstSearch()
//preorderTraversal()
//postorderTraversal()
//inorderTraversal()
};

#endif //ALGORITHM_DRAWER_HEAP_H
