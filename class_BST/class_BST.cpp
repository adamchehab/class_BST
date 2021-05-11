#include "class_BST.h"
#include <iostream>
using namespace std;

BST::BST()
{
    root = nullptr;
}

BST::~BST()
{
    root = makeEmpty(root);
}

BST::Node* BST::makeEmpty(Node* node)
{
    if (node == nullptr)
        return nullptr;
    {
        makeEmpty(node->left);
        makeEmpty(node->right);
        delete node;
    }
    return nullptr;
}

BST::Node* BST::insert(int key, Node* node)
{
    if (node == nullptr)
    {
        node = new Node;
        node->key = key;
        node->left = nullptr;
        node->right = nullptr;
    }
    // ??? < or <= what do we do if value is already in the three
    else if (key <= node->key)
        node->left = insert(key, node->left);
    else if (key > node->key)
        node->right = insert(key, node->right);
    return (node);
}

//
BST::Node* BST::removenode(int x)
{
    if (search(x) == false)
        return (nullptr);


    return nullptr;
}

BST::Node* BST::find(Node* node, int x)
{
    if (node == nullptr)
        return nullptr;
    else if (x < node->key)
        return find(node->left, x);
    else if (x > node->key)
        return find(node->right, x);
    else
        return node;
}

void BST::inorder(Node* node)
{
    if (node == nullptr)
        return;
    inorder(node->left);
    cout << node->key << ", ";
    inorder(node->right);
}

void BST::insert(int key)
{
    root = insert(key, root);
}

//
bool BST::remove(int x)
{
    return ((removenode(x) == nullptr) ? false : true);
}

bool BST::search(int x)
{
    return ((find(root, x) == nullptr) ? 0 : 1);
}

void BST::display()
{
    cout << "TREE: " << endl;
    inorder(root);
    cout << endl;
}
