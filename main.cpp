//====================================================================
// main.cpp
// Author: sammaniamsam
//====================================================================
#include "binary_search_tree/binary_search_tree.h"
#include "binary_search_tree/test_bst.h"

int main(){

    //---------------------------------
    //TESTS FOR BINARY SEARCH TREE
    //---------------------------------
    test_bst* test_bstPtr = new test_bst();
    test_bstPtr->run_bst_tests();
};


