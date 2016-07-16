//====================================================================
// main.cpp
// Author: sammaniamsam
//====================================================================
#include "binary_search_tree/binary_search_tree.h"

int main(){

    //---------------------------------
    //TESTS FOR BINARY SEARCH TREE
    //---------------------------------


    //---------------------------------
    //Test insert function
    //- - - - - - - - - - - - - - - - -
    binary_search_tree* bstPtr = new binary_search_tree();
    bstPtr->insert(5);
    bstPtr->insert(2);
    bstPtr->insert(20);
    bstPtr->insert(15);
    bstPtr->insert(13);
    bstPtr->insert(17);
    bstPtr->insert(16);
    bstPtr->insert(14);
    bstPtr->insert(25);
    bstPtr->insert(1);
    bstPtr->insert(3);
    //- - - - - - - - - - - - - - - - -


    //---------------------------------
    //Create queue
    //- - - - - - - - - - - - - - - - -
    //Create queue
    std::queue<node*>* path;
    path = new std::queue<node*>;
    //- - - - - - - - - - - - - - - - -


    //---------------------------------
    //Test preorderTraversal function
    //- - - - - - - - - - - - - - - - -
    std::cout << "\n\n";
    bstPtr->preorderTraversal(path);
    std::cout << "\n\n";
    while (!path->empty())
    {
        std::cout <<"\n"<< path->front()->key;
        path->pop();
    }
    //- - - - - - - - - - - - - - - - -


    //---------------------------------
    //Test inorderTraversal function
    //---------------------------------
    std::cout << "\n\n";
    bstPtr->inorderTraversal(path);
    std::cout << "\n\n";
    while (!path->empty())
    {
        std::cout <<"\n"<< path->front()->key;
        path->pop();
    }
    //- - - - - - - - - - - - - - - - -


    //---------------------------------
    //Test postorderTraversal function
    //- - - - - - - - - - - - - - - - -
    std::cout << "\n\n";
    bstPtr->postorderTraversal(path);
    std::cout << "\n\n";
    while (!path->empty())
    {
        std::cout <<"\n"<< path->front()->key;
        path->pop();
    }
    //- - - - - - - - - - - - - - - - -


    //---------------------------------
    //Test removeNode function
    //- - - - - - - - - - - - - - - - -
    bstPtr->removeNode(20);
    //- - - - - - - - - - -
    std::cout << "\n\n";
    bstPtr->preorderTraversal(path);
    std::cout << "\n\n";
    while (!path->empty())
    {
        std::cout <<"\n"<< path->front()->key;
        path->pop();
    }
    //- - - - - - - - - - - - - - - - -


    //---------------------------------
    //Test search function
    //- - - - - - - - - - - - - - - - -
    int key = 16;
    bstPtr->search( key, path );
    std::cout << "\n\n";
    while (!path->empty())
    {
        std::cout <<"\n"<< path->front()->key;
        path->pop();
    }
    //- - - - - - - - - - - - - - - - -


    //---------------------------------
    //Test Delete function
    //- - - - - - - - - - - - - - - - -
    std::cout << "\n\n";
    delete bstPtr;
    bstPtr = NULL;
    //- - - - - - - - - - - - - - - - -
};


