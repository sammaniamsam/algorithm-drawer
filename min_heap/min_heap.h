//====================================================================
// min_heap.h
// Author: sammaniamsam
//====================================================================
#include <iostream>
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
        node *m_pRoot; //pointer to root node in min heap
        std::queue<node *>* minHeapQueue;

        void buildBottomUp (std::queue<node *>* mhQueue);
    public:
        min_heap();
        ~min_heap();
        void insert(int& key);
//search()
//insert()
//delete()
//clear()
//breadthFirstSearch()
//deapthFirstSearch()
//preorderTraversal()
//postorderTraversal()
//inorderTraversal()
};

#endif //ALGORITHM_DRAWER_HEAP_H
