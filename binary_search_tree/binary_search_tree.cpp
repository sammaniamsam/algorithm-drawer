//====================================================================
// binary_search_tree.cpp
// Author: sammaniamsam
//====================================================================
#include "binary_search_tree.h"
//---------------------------------

//---------------------------------
//---------------------------------
//--------PRIVATE METHODS----------
//---------------------------------
//---------------------------------

//---------------------------------
//FUNCTION: destroyTree()
//PURPOSE: uses post-order traversal
//to destroy all nodes in the BST
//---------------------------------
void binary_search_tree::destroyTree(node *root)
{
    if (root == NULL) return;
    if (root->left != NULL)
        this->destroyTree(root->left);
    if (root->right != NULL)
        this->destroyTree(root->right);
    std::cout << "\nDeleting: " << root->key; //TESTING
    delete root;
    return;
}

//---------------------------------
//FUNCTION: preorderTraversal()
//PURPOSE: Performs a pre-order
//traversal of the BST and stores
//route taken in path queue
//---------------------------------
void binary_search_tree::preorderTraversal(node *root, std::queue<node *> *path)
{
    if(root != NULL)
    {
        path->push(root);
        this->preorderTraversal(root->left, path);
        this->preorderTraversal(root->right, path);
    }
}

//---------------------------------
//FUNCTION: inorderTraversal()
//PURPOSE: Performs a in-order
//traversal of the BST and stores
//route taken in path queue
//---------------------------------
void binary_search_tree::inorderTraversal(node *root, std::queue<node *> *path)
{
    if(root != NULL)
    {
        this->inorderTraversal(root->left, path);
        path->push(root);
        this->inorderTraversal(root->right, path);
    }
}

//---------------------------------
//FUNCTION: postorderTraversal()
//PURPOSE: Performs a post-order
//traversal of the BST and stores
//route taken in path queue
//---------------------------------
void binary_search_tree::postorderTraversal(node *root, std::queue<node *> *path)
{
    if(root != NULL)
    {
        this->postorderTraversal(root->left, path);
        this->postorderTraversal(root->right, path);
        path->push(root);
    }
}

//---------------------------------
//---------------------------------
//--------PUBLIC METHODS----------
//---------------------------------
//---------------------------------

//---------------------------------
//FUNCTION: binary_search_tree()
//PURPOSE: Initializes private
//member variable m_pRoot.
//---------------------------------
binary_search_tree::binary_search_tree()
{
    this->m_pRoot = NULL;
}

//---------------------------------
//FUNCTION: ~binary_search_tree()
//PURPOSE: Calls private fctn DestroyTree
//and passes in the private member variable
//m_pRoot.
//---------------------------------
binary_search_tree::~binary_search_tree()
{
    this->destroyTree(this->m_pRoot);
}

//---------------------------------
//FUNCTION: insert()
//PURPOSE: Creates a new node and
//assigns it a key. Then, searches
//for a position within the binary
//tree to insert the new node.
//---------------------------------
void binary_search_tree::insert(int key)
{
    //define variables
    node *temp, *back, *newNode;
    temp = this->m_pRoot, back = NULL;
    newNode = new node(key);

    //search for place to insert
    while(temp != NULL)
    {
        back = temp;
        if(newNode->key <= temp->key)
            temp = temp->left;
        else
            temp = temp->right;
    }

    //if newNode is root node
    if(back == NULL)
    {
        std::cout << "\nExecuting back == NULL";//TESTING
        this->m_pRoot = newNode;
        std::cout << "\nRoot: " << this->m_pRoot->key;//TESTING
    }

    //newNode is not root node
    else
    {
        if(newNode->key <= back->key)
        {
            back->left = newNode;
            std::cout << "\n\n" << back->left->key << " is left of: " << back->key;//TESTING
        }
        else
        {
            back->right = newNode;
            std::cout << "\n\n" << back->right->key << " is right of: " << back->key;//TESTING
        }
    }
}

//---------------------------------
//FUNCTION: search()
//PURPOSE: Looks for node in BST
//that has the same key as the
//key argument passed in. The queue
//argument passed in stores the
//traversal path. Finally, if no
//match is found then false is
//returned
//---------------------------------
bool binary_search_tree::search(int& key, std::queue<node *> *path)
{
    //define variables
    node *temp;
    temp = m_pRoot;
    path->push(temp);

    //search for key in BST
    while((temp != NULL) && (key != temp->key))
    {
        if(key < temp->key)
            temp = temp->left;
        else
            temp = temp->right;
        path->push(temp);
    }

    //did not find key
    if(temp == NULL)
    {
        std::cout << "\n" << "Key: " << key << " not found" << "\n";//TESTING
        return false;
    }
    else
        return true;
}

//---------------------------------
//FUNCTION: preorderTraversal()
//PURPOSE: Calls private fctn
//preorderTraversal() and passes
//it queue that stores the traversal
//path.
//---------------------------------
void binary_search_tree::preorderTraversal(std::queue<node *> *path)
{
    this->preorderTraversal(this->m_pRoot, path);
}

//---------------------------------
//FUNCTION: inorderTraversal()
//PURPOSE: Calls private fctn
//inorderTraversal() and passes
//it queue that stores the traversal
//path.
//---------------------------------
void binary_search_tree::inorderTraversal(std::queue<node *> *path)
{
    this->inorderTraversal(this->m_pRoot, path);
}

//---------------------------------
//FUNCTION: postorderTraversal()
//PURPOSE: Calls private fctn
//postorderTraversal() and passes
//it queue that stores the traversal
//path.
//---------------------------------
void binary_search_tree::postorderTraversal(std::queue<node *> *path)
{
    this->postorderTraversal(this->m_pRoot, path);
}

//---------------------------------
//FUNCTION: removeNode()
//PURPOSE: Removes a single node
//from the BST. Two cases:
//Case 1 -- delete node with no
//          children or one child
//Case 2 -- delete node with two
//          children
//---------------------------------
bool binary_search_tree::removeNode(int key)
{
    //define variables
    node *back, *temp, *delParent, *delNode;
    temp = m_pRoot, back = NULL;

    //search for node to delete
    while((temp != NULL) && (key != temp->key))
    {
        back = temp;
        if(key < temp->key)
            temp = temp->left;
        else
            temp = temp->right;
    }

    //didn't find the node to remove
    if(temp == NULL)
    {
        std::cout << "\n" << "key: " << key << " was not found" << "\n";//TESTING
        return false;
    }

    //found node to remove
    else
    {
        //deleting the root
        if(temp == m_pRoot)
        {
            delNode = m_pRoot;
            delParent = NULL;
        }
        else
        {
            delNode = temp;
            delParent = back;
        }
    }
    //- - - - - - - - - - - - - - - - - - - - - - - - - -
    //Case 1: Deleting node with no children or one child
    //- - - - - - - - - - - - - - - - - - - - - - - - - -
    //node to delete has left child
    if (delNode->right == NULL)
    {
        //if deleting root
        if(delParent == NULL)
        {
            m_pRoot = delNode->left;
            delete delNode;
            return true;
        }
        else
        {
            if(delParent->left == delNode)
                delParent->left = delNode->left;
            else
                delParent->right = delNode->left;
            delete delNode;
            return true;
        }
    }
    //node to delete has right child
    else
    {
        if(delNode->left == NULL)
        {
            //if deleting root
            if(delParent == NULL)
            {
                m_pRoot = delNode->right;
                delete delNode;
                return true;
            }
            else
            {
                if(delParent->left == delNode)
                    delParent->left = delNode->right;
                else
                    delParent->right = delNode->right;
                delete delNode;
                return true;
            }
        }
        //- - - - - - - - - - - - - - - - - - - -
        //Case 2: Deleting node with two children
        //- - - - - - - - - - - - - - - - - - - -
        else
        {
            temp = delNode->left;
            back = delNode;

            //get the largest node in
            //delNode's left child's subtree
            while(temp->right != NULL)
            {
                back = temp;
                temp = temp->right;
            }
            //Copy the replacement value(s) into the node to be removed
            delNode->key = temp->key;

            //Remove the replacement node from the tree
            if(back == delNode)
                back->left = temp->left;
            else
                back->right = temp->left;
            delete temp;
            return true;
        }//end Case 2
    }
}