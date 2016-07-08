#include "avl.h"

AVL::AVL()
{

    this->_root = NULL;
}

AVL::~AVL()
{

}

int AVL::countNodes(node *n)
{
    if(n==NULL)
        return 0;
    else
    {
        int cnt = 1;
        cnt += this->countNodes(n->left);
        cnt += this->countNodes(n->right);
        return cnt;
    }
}

void AVL::postorder(node *n, std::queue<node *> *path)
{

}

void AVL::preorder(node *n, std::queue<node *> *path)
{
    if(n!=NULL)
    {
//        std::cout << n->key << " ";
        path->push(n);
        preorder(n->left, path);
        preorder(n->right, path);
    }
}

void AVL::inorder(node *n, std::queue<node*>* path)
{
    if(n!=NULL)
    {
        inorder(n->left, path);
        path->push(n);
//        std::cout<<n->key<<" ";
        inorder(n->right, path);
    }
}

bool AVL::search(int val, node *n)
{

}

node *AVL::insert(int key, node *n)
{
    // If there are no other nodes..
    if(n==NULL)
        n = new node(key);
    // Go left young man!
    else if(key<n->key)
    {
        // Recursively place the node where it belongs
        n->left = insert(key, n->left);
        // Rebalance after the node has been added
        if(this->getHeight(n->left)-this->getHeight(n->right) == 2)
        {

            if(key<n->left->key)
                n = rotateLeftChild(n);
            else
                n = doubleLeftChild(n);
        }
    }
    // Go right young man!
    else if(key>n->key)
    {
        // Recursively place the node where it belongs
        n->right = insert(key, n->right);
        // Rebalance after the node has been added
        if(this->getHeight(n->right)-this->getHeight(n->left) ==2)
        {
            if(key>n->right->key)
                n = rotateRightChild(n);
            else
                n = doubleRightChild(n);
        }
    }
    n->height = this->getMax(this->getHeight(n->left), this->getHeight(n->right)) + 1;
    return n;
}

void AVL::makeEmpty()
{

}

void AVL::insert(int key)
{
    this->_root = this->insert(key, this->_root);
}

void AVL::inorder(std::queue<node *> *path)
{
    inorder(this->_root,path);
}

void AVL::preorder(std::queue<node *> *path)
{
    preorder(this->_root, path);
}

void AVL::postorder(std::queue<node *> *path)
{

}

bool AVL::isEmpty()
{
    return (this->_root==NULL);
}

bool AVL::search(int val, std::queue<node *> *path)
{

}

int AVL::getHeight(node *n)
{
    return (n==NULL ? -1 : n->height);
}

int AVL::getMax(int left, int right)
{
    return (left>right ? left : right);
}

int AVL::countNodes()
{
    return countNodes(this->_root);
}

// Left heavy (LL)
node *AVL::rotateLeftChild(node *n)
{
    node* tmpNode = n->left;
    n->left = tmpNode->right;
    tmpNode->right = n;
    n->height = this->getMax(this->getHeight(n->left), this->getHeight(n->right)) + 1;
    tmpNode->height = this->getMax(this->getHeight(tmpNode->left), n->height) + 1;
    return tmpNode;
}

// Right heavy (RR)
node *AVL::rotateRightChild(node *n)
{
    node* tmpNode = n->right;
    n->right = tmpNode->left;
    tmpNode->left = n;
    n->height = this->getMax(this->getHeight(n->left), this->getHeight(n->right)) + 1;
    tmpNode->height = this->getMax(this->getHeight(tmpNode->right), n->height) + 1;
    return tmpNode;
}

// (LR)
node *AVL::doubleLeftChild(node *n)
{
    n->left = rotateRightChild(n->left);
    return rotateLeftChild(n);
}

// (RL)
node *AVL::doubleRightChild(node *n)
{
    n->right = rotateLeftChild(n->right);
    return rotateRightChild(n);
}

