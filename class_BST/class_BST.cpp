#include "class_BST.h"
#include <iostream>
using namespace std;

BST::BST()
{
    root = NULL;
}

BST::~BST()
{
    root = makeEmpty(root);
}

BST::Node* BST::makeEmpty(Node* node)
{
    if (node == NULL)
        return NULL;
    {
        makeEmpty(node->left);
        makeEmpty(node->right);
        delete node;
    }
    return NULL;
}

BST::Node* BST::insertNode(int key, Node* node)
{
    if (node == NULL)
    {
        node = new Node;
        node->key = key;
        node->left = NULL;
        node->right = NULL;
    }
    // ??? < or <= what do we do if value is already in the three
    else if (key <= node->key)
        node->left = insertNode(key, node->left);
    else if (key > node->key)
        node->right = insertNode(key, node->right);
    return (node);
}

BST::Node* BST::findMin(Node* node) 
{
    if (node->left != NULL)
        node = findMin(node->left);
    return node;
}

BST::Node* BST::deleteNode(Node* node, int x)
{
    Node* temp;
    if (node == NULL) 
        return node;
    else if (x < node->key)
        node->left = deleteNode(node->left, x);
    else if (x > node->key)
        node->right = deleteNode(node->right, x);
    else if (node->left && node->right)
    {
        temp = findMin(node->right);
        node->key = temp->key;
        node->right = deleteNode(node->right, node->key);
    }
    else
    {
        temp = node;
        if (node->left == NULL)
            node = node->right;
        else if (node->right == NULL)
            node = node->left;
        delete temp;
    }
    return node;
}

BST::Node* BST::findNode(Node* node, int x)
{
    if (node == NULL)
        return NULL;
    else if (x < node->key)
        return findNode(node->left, x);
    else if (x > node->key)
        return findNode(node->right, x);
    else
        return node;
}

void BST::inorder(Node* node)
{
    if (node == NULL)
        return;
    inorder(node->left);
    cout << node->key << " ";
    inorder(node->right);
}

void BST::insert(int key)
{
    root = insertNode(key, root);
}

bool BST::remove(int x)
{
    root = deleteNode(root , x);
    return ((search(x) == false) ? false : true);
}

bool BST::search(int x)
{
    return ((findNode(root, x) == NULL) ? 0 : 1);
}

void BST::display()
{
    cout << "Tree: ";
    inorder(root);
    cout << endl;
}
