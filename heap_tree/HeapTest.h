//
// Created by Jacob Deep on 7/16/2016.
//
#include "MaxHeap.h"
#include <iostream>

using namespace std;

#ifndef ALGORITHM_EXTRA_CREDIT_TEST_H
#define ALGORITHM_EXTRA_CREDIT_TEST_H


class testHeap {
    private:
        HeapSort *heapSort;
        std::queue<node*>* path;
        void testInsert();
        void testPreOrder();
        void testInorder();
        void testPostOrder();
        void testSearch();
        void testBuildMaxHeap();
        void printStuff(std::queue<node*> *queue);
        void testCountNodes();

    public:
        testHeap();
        ~testHeap();
        void runTests();
};


#endif //ALGORITHM_EXTRA_CREDIT_TEST_H
