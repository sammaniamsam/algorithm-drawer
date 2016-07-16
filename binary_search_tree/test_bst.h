//====================================================================
// test_bst.h
// Author: sammaniamsam
//====================================================================
#include "binary_search_tree.h"
//---------------------------------

#ifndef ALGORITHM_DRAWER_TEST_BST_H_H
#define ALGORITHM_DRAWER_TEST_BST_H_H

//---------------------------------
class test_bst {

    private:
        binary_search_tree* bstPtr; //ptr to bst
        std::queue<node*>* path; //ptr queue, stores traversal path

        void test_bst_insert();
        void test_bst_preorderTraversal();
        void test_bst_inorderTraversal();
        void test_bst_postorderTraversal();
        void test_bst_removeNode();
        void test_bst_search();
        void test_bst_destroyTree();
        void print_queue_content(std::queue<node*>* queuePtr);
    public:
        test_bst();
        ~test_bst();
        void run_bst_tests();
};

#endif //ALGORITHM_DRAWER_TEST_BST_H_H
