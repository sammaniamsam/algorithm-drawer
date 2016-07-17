//
// Created by Jacob Deep on 7/16/2016.
//

#include "HeapTest.h"

testHeap::testHeap() {
    this->heapSort = new HeapSort;
    this->path = new queue<node*>;
}

void testHeap::testInsert() {
    int numbers[] = {8, 6, 334,31234,13425,13,5,23,52345,2345,32};
    int heapSize = 11;
    cout << "inserting nodes\n"<< endl;
    for(int i = 0; i < heapSize; i++) {
        heapSort->insert(numbers[i]);
    }
}

void testHeap::testInorder() {
    this->heapSort->inorder(this->path);
    cout << "testing inorder";
    this->printStuff(this->path);
    cout << "\n";
}

void testHeap::testPreOrder() {
    this->heapSort->preOrder(this->path);
    cout << "testing preorder";
    this->printStuff(this->path);
    cout << "\n";
}

void testHeap::testPostOrder() {
    this->heapSort->postOrder(this->path);
    cout << "testing postorder";
    this->printStuff(this->path);
    cout << "\n";
}


void testHeap::testBuildMaxHeap() {
    this->heapSort->buildMaxHeap(this->path);
    cout << "building max heap";
    this->printStuff(this->path);
    cout << "\n";
}

void testHeap::testSearch() {
    int val = 334;
    heapSort->search(val, this->path);
    cout << "testing search";
    this->printStuff(this->path);
    cout << "\n";
}

void testHeap::printStuff(std::queue<node *> *queue) {
        while(!queue->empty()) {
            cout << "\n" << queue->front()->key;
            queue->pop();
        }
}

void testHeap::runTests() {
    this->testInsert();
    this->testPostOrder();
    this->testPreOrder();
    this->testInorder();
    //this->testSearch();
    //this->testBuildMaxHeap();

}