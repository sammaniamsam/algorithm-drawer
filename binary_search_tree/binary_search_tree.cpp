//====================================================================
// binary_search_tree.cpp
// Author: sammaniamsam
//====================================================================
//##############################################################################################################################
#include "binary_search_tree.h"
//##############################################################################################################################
//The constructor shall set the private pointer m_pRoot to NULL
binary_search_tree::binary_search_tree()
{
    m_pRoot = NULL;
}
//##############################################################################################################################
//The destructor shall call the private member function DestroyTree() to remove and delete all nodes in the tree.
binary_search_tree::~binary_search_tree()
{
    //DestroyTree(m_pRoot);
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
    temp = m_pRoot, back = NULL;
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
        m_pRoot = newNode;
        std::cout << "\nRoot: " << m_pRoot->key;//TESTING
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
//This function shall call the private function PrintAll() passing in the root of the tree.
void binary_search_tree::PrintAll()
{
    PrintAll(m_pRoot);
}
//##############################################################################################################################
//This function shall call the private function PrintAll() passing in the root of the tree.
void binary_search_tree::PrintAll(node *root)
{
    if(root != NULL)
    {
        //Print left sub-tree
        PrintAll(root->left);
        std::cout << "\n" << root->key;//TESTING
        //Print right sub-tree
        PrintAll(root->right);
    }
}
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
//##############################################################################################################################
//This function shall recursively traverse (post-order traversal) and destroy all
//nodes in the tree
/*void Translator::DestroyTree(TNode *rt)
{
    if (rt == NULL)
        return;
    if (rt->left != NULL)
        DestroyTree(rt->left);
    if (rt->right != NULL)
        DestroyTree(rt->right);
    std::cout << "\nDeleting: " << rt->EngWord;			//TESTING
    delete rt;
    rt = NULL;//TESTING
    return;
}*/