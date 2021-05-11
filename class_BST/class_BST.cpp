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

BST::Node* BST::insert(int key, Node* node)
{
    if (node == nullptr)
    {
        node = new Node;
        node->key = key;
        node->left = nullptr;
        node->right = nullptr;
    }
    else if (key <= node->key)
        node->left = insert(key, node->left);
    else if (key > node->key)
        node->right = insert(key, node->right);
    return (node);
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


void BST::insert(int key)
{
    root = insert(key, root);
}

// ЛКП (обход дерева)
void BST::inorder(Node* node)
{
    if (node == nullptr)
        return;
    inorder(node->left);
    cout << node->key << " ";
    inorder(node->right);
}

void BST::display()
{
    inorder(root);
    cout << endl;
}
