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
//FUNCTION: DestroyTree()
//PURPOSE: uses post-order traversal
//to destroy all nodes in the BST
//---------------------------------
void binary_search_tree::DestroyTree(node *root)
{
    if (root == NULL) return;
    if (root->left != NULL)
        this->DestroyTree(root->left);
    if (root->right != NULL)
        this->DestroyTree(root->right);
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
    this->DestroyTree(this->m_pRoot);
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

//##############################################################################################################################
//This function shall take a single char array argument (the alien word). The function shall locate the alien word
//in the binary tree, remove it from the tree and return the TNode structure to the caller. If the alien word was
//not found then it shall return NULL.
/*TNode *Translator::RemoveWord(char *aWord)
{
    //define variables
    TNode *back, *temp, *delParent, *delNode;
    temp = m_pRoot, back = NULL;
    TNode *rNode = new TNode();
    //rNode->left = rNode->right = NULL;	//TESTING

    //locate the aWord in the binary tree
    while((temp != NULL) && (strcmp(aWord, temp->key) != 0))
    {
        back = temp;
        if(strcmp(aWord, temp->key) < 0)
            temp = temp->left;
        else
            temp = temp->right;
    }

    //Didn't find the one to remove
    if(temp == NULL)
    {
        std::cout << "\naWord " << aWord << " was not found. Nothing removed\n";
        delete rNode;	//TESTING
        return NULL;
    }

        //found node to remove
    else
    {
        //Deleting the root
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

        //Copy contents of node that was found into node that is to be returned
        strcpy(rNode->key, delNode->key);
        strcpy(rNode->EngWord, delNode->EngWord);
    }

    //Case 1: Deleting node with no children or one child
    if (delNode->right == NULL)
    {
        //If deleting root
        if(delParent == NULL)
        {
            m_pRoot = delNode->left;
            delete delNode;
            return rNode;
        }
        else
        {
            if(delParent->left == delNode)
                delParent->left = delNode->left;
            else
                delParent->right = delNode->left;
            delete delNode;
            return rNode;
        }
    }//end case 1
        //There is at least one child
    else
    {
        //Only 1 child and it is on the right
        if(delNode->left == NULL)
        {
            if(delParent == NULL)
            {
                m_pRoot = delNode->right;
                delete delNode;
                return rNode;
            }
            else
            {
                if(delParent->left == delNode)
                    delParent->left = delNode->right;
                else
                    delParent->right = delNode->right;
                delete delNode;
                return rNode;
            }
        }
            //Case 2: Deleting node with two children
        else
        {
            temp = delNode->left;
            back = delNode;

            while(temp->right != NULL)
            {
                back = temp;
                temp = temp->right;
            }
            //Copy the replacement values into the node to be removed
            strcpy(delNode->key, temp->key);
            strcpy(delNode->EngWord, temp->EngWord);

            //Remove the replacement node from the tree
            if(back == delNode)
                back->left = temp->left;
            else
                back->right = temp->left;
            delete temp;
            return rNode;
        }//end case 2
    }//end at least one child
}*/
//##############################################################################################################################
//This function shall take two char array arguments: an alien word and its' English equivalent.
//The function shall serch the binary tree, locate the alien word and change the English translation
//to the new English word then return true. If the alien word was not found then it shall return false.
/*bool Translator::ChangeWord(char *aWord, char *eWord)
{
    TNode *temp;
    temp = Search(aWord);

    if(temp == NULL)
        return false;
    else
    {
        strcpy(temp->EngWord, eWord);
        return true;
    }
}*/
//##############################################################################################################################
//This function shall take a string argument consisting of alien words separated by spaces to be translated into English.
//The function shall parse out each word, look it up in the binary tree and print the English translation. All words
//translated from a single string will appear on a single line on the screen.
/*void Translator::Translate(char *line)
{
    char *token = NULL;
    TNode *temp;
    char tokChars[11] = {' ',',',':',';','.','"','\'','!','?'};

    //Print alien words
    //cout <<"\n" << line << "\n";	//COMMENT BACK IN!!!

    //Get first word in the line and translate it
    token = strtok(line, tokChars);
    temp = Search(token);

    //Translate the rest of the line
    while(token != NULL)
    {
        if(temp != NULL)
            std::cout << temp->EngWord << " ";
        else
            std::cout << "UNKNOWN ";
        token = strtok(NULL, tokChars);
        if (token != NULL)
            temp = Search(token);
    }
}*/
//##############################################################################################################################
//This function shall search the tree and return a pointer to the node wit the key aWord
//or NULL if the word was not found.
/*TNode *Translator::Search(char *aWord)
{
    TNode *temp;
    temp = m_pRoot;

    while((temp != NULL) && (strcmp(aWord, temp->key) != 0))
    {
        if(strcmp(aWord, temp->key) < 0)
            temp = temp->left;
        else
            temp = temp->right;
    }
    if(temp == NULL)
    {
        std::cout << "\nKey: " << aWord << " not found";	//TESTING
        return NULL;
    }
    else
        return temp;
}*/