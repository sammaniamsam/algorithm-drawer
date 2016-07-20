//====================================================================
// main.cpp
// Author: sammaniamsam
//====================================================================
//#include "binary_search_tree/binary_search_tree.h"
//#include "binary_search_tree/test_bst.h"
#include "min_heap/min_heap.h"


int main(){

    //---------------------------------
    //TESTS FOR BINARY SEARCH TREE
    //---------------------------------
    //test_bst* test_bstPtr = new test_bst();
    //test_bstPtr->run_bst_tests();

    //---------------------------------
    //TESTS FOR MIN HEAP
    //---------------------------------
    min_heap* mhPtr = new min_heap();
    int iArray[] = {9,7,5,8,6,2};

    //test insert()
    for(int i=0; i < 6; i++)
        mhPtr->insert(iArray[i]);

    int fake = 22;

    //create queue
    std::queue<node *>* qPtr = new std::queue<node *>;

    //test search()
    if(mhPtr->search(fake, qPtr))
        std::cout << "\n\nFound Key!";
    else
        std::cout << "\n\nKey NOT Found!";
    std::cout << "\n";

    //test removeNode()
    if(mhPtr->removeNode())
        std::cout << "\n\nSuccessful removal!";
    else
        std::cout << "\n\nNOT successful removal!";
    std::cout << "\n";

    //test preorderTraversal()
    while (!qPtr->empty()) {qPtr->pop();}
    mhPtr->preorderTraversal(qPtr);

    //print queue
    while (!qPtr->empty())
    {
        std::cout <<"\n"<< qPtr->front()->key;
        qPtr->pop();
    }

    //test inorderTraversal()
    while (!qPtr->empty()) {qPtr->pop();}
    mhPtr->inorderTraversal(qPtr);

    std::cout << "\n\n";

    //print queue
    while (!qPtr->empty())
    {
        std::cout <<"\n"<< qPtr->front()->key;
        qPtr->pop();
    }

    //test postorderTraversal()
    while (!qPtr->empty()) {qPtr->pop();}
    mhPtr->postorderTraversal(qPtr);

    std::cout << "\n\n";

    //print queue
    while (!qPtr->empty())
    {
        std::cout <<"\n"<< qPtr->front()->key;
        qPtr->pop();
    }

    //test ~min_heap()
    delete mhPtr;
};


