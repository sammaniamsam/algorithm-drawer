//
// Created by Jacob Deep on 7/9/2016.
//

#include <queue>
#include <vector>
#include <iostream>

#ifndef HEAPSORT_H
#define HEAPSORT_H

using namespace std;

struct node {
    int key;
    node* left;
    node* right;
    node* parent;
    unsigned char height;
    node(int k) {key = k; parent = left = right = NULL; height = 0;}
};

class HeapSort {
    private:
        node* rootNode;
        int countNodes(node* n);
        void postOrder(node* n, queue<node*> *path);
        void preOrder(node* n, queue<node*> *path);
        void inorder(node* n, queue<node*> *path);
        bool search(int val, node* n);
        node* insert(int key, node* n);


    public:
        HeapSort();
        ~HeapSort();
        bool isEmpty();
        void inorder(queue<node*> *path);
        void preOrder(queue<node*> *path);
        void postOrder(queue<node*> *path);
        void buildMaxHeap(queue<node *> *path);
        bool search(int val, queue<node*> *path);
        int countNodes();
        bool deleteTree();
        void insert(int key);
        void heapSort(int numberEntered[], int heapSize);

};


#endif
