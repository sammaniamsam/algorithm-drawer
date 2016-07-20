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
//FUNCTION: topDown()
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
//FUNCTION: defineNodePtrs()
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
//FUNCTION: setPtrsNull()
//PURPOSE:
//---------------------------------
void min_heap::setPtrsNull() {

    //define variables
    unsigned long i = 0;
    std::vector<node *>::iterator it;

    //iterate though heap
    for (it = this->minHeapVector->begin(); it != this->minHeapVector->end(); ++it, i++) {
        //set node ptrs to NULL
        this->minHeapVector->at(i)->left = this->minHeapVector->at(i)->right = NULL;
    }
}

//---------------------------------
//FUNCTION: preorderTraversal()
//PURPOSE: Performs a pre-order
//traversal of the heap and stores
//route taken in path queue
//---------------------------------
void min_heap::preorderTraversal(node *root, std::queue<node *> *path)
{
    if(root != NULL)
    {
        path->push(root);
        this->preorderTraversal(root->left, path);
        this->preorderTraversal(root->right, path);
    }
}

//---------------------------------
//FUNCTION: inorderTraversal()
//PURPOSE: Performs a in-order
//traversal of the heap and stores
//route taken in path queue
//---------------------------------
void min_heap::inorderTraversal(node *root, std::queue<node *> *path)
{
    if(root != NULL)
    {
        this->inorderTraversal(root->left, path);
        path->push(root);
        this->inorderTraversal(root->right, path);
    }
}

//---------------------------------
//FUNCTION: postorderTraversal()
//PURPOSE: Performs a post-order
//traversal of the heap and stores
//route taken in path queue
//---------------------------------
void min_heap::postorderTraversal(node *root, std::queue<node *> *path)
{
    if(root != NULL)
    {
        this->postorderTraversal(root->left, path);
        this->postorderTraversal(root->right, path);
        path->push(root);
    }
}

//---------------------------------
//---------------------------------
//--------PUBLIC METHODS-----------
//---------------------------------
//---------------------------------

//---------------------------------
//FUNCTION: min_heap()
//PURPOSE:
//---------------------------------
min_heap::min_heap() {

    this->minHeapVector = new std::vector<node *>;
}

//---------------------------------
//FUNCTION: ~min_heap()
//PURPOSE:
//---------------------------------

//DESTRUCTOR FUNCTION IS NOT CORRECT
//NEEDS TO SET EACH HEAP NODES' PTRS
//TO NULL
min_heap::~min_heap() {

    //define variables
    node* nPtr;

    //set node ptrs to null
    this->setPtrsNull();

    while(!this->minHeapVector->empty()) {
        nPtr = this->minHeapVector->back();
        delete nPtr;
        this->minHeapVector->pop_back();
    }
    delete this->minHeapVector; this->minHeapVector = NULL;
}

//---------------------------------
//FUNCTION: insert()
//PURPOSE:
//---------------------------------
void min_heap::insert(int& key) {

    //define variables
    node* newNode;
    newNode = new node(key);
    //initialize node ptrs to null
    this->setPtrsNull();

    //add newNode to heap vector
    this->minHeapVector->push_back(newNode);
    //heapify using top down
    this->topDown(this->minHeapVector->size());
    //define heap nodes' ptrs
    this->defineNodePtrs(this->minHeapVector->size());
}

//---------------------------------
//FUNCTION: removeNode()
//PURPOSE: Deletes the heaps root
//node
//---------------------------------
bool min_heap::removeNode() {

    //define variables
    node *leaf, *delNode;
    //initialize node ptrs to null
    this->setPtrsNull();

    if(!this->minHeapVector->empty()) {
        //get last leaf
        leaf = this->minHeapVector->back();
        //set leaf ptrs to NULL
        leaf->left = leaf->right = NULL;
        //swap last leaf and root
        delNode = this->minHeapVector->back() = this->minHeapVector->front();
        this->minHeapVector->front() = leaf;
        //delete last leaf
        delNode->left = delNode->right = NULL; delete delNode;
        this->minHeapVector->pop_back();
        //heapify using top down
        this->topDown((this->minHeapVector->size()+1)/2);
        //define heap nodes' ptrs
        this->defineNodePtrs(this->minHeapVector->size());
        return true;
    }
    //heap is empty
    else return false;
}

//---------------------------------
//FUNCTION: search()
//PURPOSE:
//---------------------------------
bool min_heap::search(int& key, std::queue<node *> *path) {

    //define variables
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

//---------------------------------
//FUNCTION: preorderTraversal()
//PURPOSE:
//---------------------------------
void min_heap::preorderTraversal(std::queue<node *> *path) {

    this->preorderTraversal(this->minHeapVector->front(), path);
}

//---------------------------------
//FUNCTION: inorderTraversal()
//PURPOSE:
//---------------------------------
void min_heap::inorderTraversal(std::queue<node *> *path) {

    this->inorderTraversal(this->minHeapVector->front(), path);
}

//---------------------------------
//FUNCTION: postorderTraversal()
//PURPOSE:
//---------------------------------
void min_heap::postorderTraversal(std::queue<node *> *path) {

    this->postorderTraversal(this->minHeapVector->front(), path);
}

