//
// Created by Jacob Deep on 7/9/2016.
//

#include "MaxHeap.h"

HeapSort::HeapSort() {
    this->rootNode = NULL;
}

HeapSort::~HeapSort() {
 }

int HeapSort::countNodes(node *n) {
    if(n == NULL) {
        return 0;
    }
    else {
        int count = 1;
        count += this->countNodes(n->left);
        count += this->countNodes(n->right);
        return count;
    }
}

void HeapSort::postOrder(node *n, queue<node *> *path) {
    if(n != NULL) {
        this->postOrder(n->right,path);
        this->postOrder(n->left, path);
        path->push(n);
    }

}

void HeapSort::preOrder(node *n, queue<node *> *path) {
    if (n != NULL) {
        path->push(n);
        preOrder(n->left, path);
        preOrder(n->right, path);

    }
}

void HeapSort::inorder(node *n, queue<node *> *path) {
    if (n != NULL) {
        inorder(n->left, path);
        path->push(n);
        inorder(n->right, path);
    }
}

node* HeapSort::insert(int key, node *n) {
    if(n == NULL) {
        n = new node(key);
    }
    else if(key < n->key) {
        n->left = insert(key, n->left);
    }
    else if(key > n->key) {
        n->right = insert(key, n->right);
    }
    return n;
}

void HeapSort::insert(int key) {
    this->rootNode = this->insert(key, this->rootNode);
}

void HeapSort::inorder(queue<node *> *path) {
    inorder(this->rootNode, path);
}

void HeapSort::preOrder(queue<node *> *path) {
    preOrder(this->rootNode, path);
}
void HeapSort::postOrder(queue<node *> *path) {
    postOrder(this->rootNode, path);

}
bool HeapSort::isEmpty() {
    return(this->rootNode == NULL);
}
bool HeapSort::deleteTree() {

}

bool HeapSort::search(int val, queue<node *> *path) {
    node* tempNode;
    tempNode = rootNode;
    path->push(tempNode);



    while (tempNode != NULL && val != tempNode->key); {
        if(val < tempNode->key) {
            tempNode = tempNode->left;
        }
        else {
            tempNode = tempNode->right;
        }
        path->push(tempNode);
    }
    if(tempNode == NULL) {
        cout << "Value Not found(" << val << ")" << endl;
        return false;
    }
    else {
        return true;

    }
}

int HeapSort::countNodes() {
    return countNodes(this->rootNode);
}

// Below Code is broken
void HeapSort::buildMaxHeap(queue<node *> *path) {
    int count = countNodes();
    int* test;
    test = new int[count];
    vector<node*>* temp;

    cout << count<< endl;
    //trying to copy the data in the queue to the array so i can index over it properly
    while(rootNode!=NULL) {
        for(int i = 0; i<count; i++) {
            test[i] = (int)rootNode;
            path->pop();
            cout << test[i];
        }
    }
//// Below Code is broken
// Was trying to figure out how to iterate over the queue but was having trouble
//    void HeapSort::buildMaxHeap(queue<node *> *path, int heapSize) {
//        int test [heapSize];
//        vector<node*>* temp;
//
//        while(!path->empty()) {
//            for(int i = 0; i<heapSize; i++) {
//                test[i] = (int)path->front();
//                path->pop();
//                cout << test[i];
//            }
//        }
//    for(int i = 0; i < heapSize; i++){
//        int index = i;
//        while(path->front() < path->front()+1){
//
//            temp = path[index/2];
//            path[index/2] = path[index];
//            path[index] = temp;
//            index=index/2;
//        }
//    }
}

//void HeapSort::heapSort(int numbersEntered[], int heapSize) {
//    while(heapSize >= 0){
//        buildMaxHeap(numbersEntered, heapSize);
//
//        int temp = numbersEntered[1];
//        numbersEntered[1] = numbersEntered[numbersEntered[0]];
//        numbersEntered[numbersEntered[0]] = temp;
//
//        for(int i = 1; i < heapSize; i++){
//            int index = i;
//
//            while(numbersEntered[index/2] < numbersEntered[index] && (index/2)!=0){
//                int temp1 = numbersEntered[index/2];
//                numbersEntered[index/2] = numbersEntered[index];
//                numbersEntered[index] = temp1;
//                index=index/2;
//
//            }
//        }
//        heapSize--;
//    }
//
//    cout << "sorted array: " << endl;
//    for(int i = 0; i < heapSize; i++) {
//        cout << numbersEntered[i] << endl;
//    }
//}
