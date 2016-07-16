//====================================================================
// test_bst.h
// Author: sammaniamsam
//====================================================================
#include "test_bst.h"
//---------------------------------

//---------------------------------
//---------------------------------
//--------PRIVATE METHODS----------
//---------------------------------
//---------------------------------

void test_bst::test_bst_insert() {
    int iArray[] = {5,2,20,15,13,17,16,14,25,1,3};
    int iArraySize = 11;
    std::cout << "\ninsert nodes";
    for(int i = 0; i < iArraySize; i++)
        this->bstPtr->insert(iArray[i]);
    std::cout << "\n\n";
;}

void test_bst::test_bst_preorderTraversal() {
    this->bstPtr->preorderTraversal(this->path);
    std::cout << "\npre-order traversal";
    this->print_queue_content(this->path);
}

void test_bst::test_bst_inorderTraversal() {
    this->bstPtr->inorderTraversal(this->path);
    std::cout << "\nin-order traversal";
    this->print_queue_content(this->path);
}

void test_bst::test_bst_postorderTraversal() {
    this->bstPtr->postorderTraversal(this->path);
    std::cout << "\npost-order traversal";
    this->print_queue_content(this->path);
}

void test_bst::test_bst_removeNode() {
    int key = 20;
    this->bstPtr->removeNode(key);
    std::cout << "\nremove node: " << key;
    this->bstPtr->preorderTraversal(this->path);
    this->print_queue_content(this->path);
}

void test_bst::test_bst_search() {
    int key = 16;
    bstPtr->search( key, this->path );
    std::cout << "\nsearch node: " << key;
    this->print_queue_content(this->path);
}

void test_bst::test_bst_destroyTree() {
    delete this->bstPtr; this->bstPtr = NULL;
}

//---------------------------------
//Does: Prints the contents of the
//queue.
//---------------------------------
void test_bst::print_queue_content(std::queue<node*>* queuePtr) {
    std::cout << "\n";
    while (!queuePtr->empty())
    {
        std::cout <<"\n"<< queuePtr->front()->key;
        queuePtr->pop();
    }
    std::cout << "\n\n";
}

//---------------------------------
//---------------------------------
//--------PUBLIC METHODS-----------
//---------------------------------
//---------------------------------

//---------------------------------
//Does: Instantiates private member
//variables
//---------------------------------
test_bst::test_bst() {
    this->bstPtr = new binary_search_tree();
    this->path = new std::queue<node*>;
}

//---------------------------------
//Does: De-allocates dynamic instances
//stored in private member variables
//---------------------------------
test_bst::~test_bst() {
    this->test_bst_destroyTree();
    while (!this->path->empty()) this->path->pop();
    delete this->path;
}

//---------------------------------
//Does: Calls all private member
//functions to test the BST
//---------------------------------
void test_bst::run_bst_tests() {
    this->test_bst_insert();
    this->test_bst_preorderTraversal();
    this->test_bst_inorderTraversal();
    this->test_bst_postorderTraversal();
    this->test_bst_removeNode();
    this->test_bst_search();
}