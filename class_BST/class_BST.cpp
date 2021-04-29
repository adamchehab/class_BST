#include "class_BST.h"
#include <iostream>
using namespace std;

BST::BST()
{
    root = nullptr;
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

void BST::insert(int key)
{
    root = insert(key, root);
}

BST::Node* BST::search(int key)
{
    root = find(root, key);
}

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
