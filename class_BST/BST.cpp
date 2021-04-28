#include "BST.h"
#include <iostream>

Node::Node(int key)
{
    this->key = key;
    this->left = nullptr;
    this->right = nullptr;
}

BST::BST()
{
    this->root = nullptr;
}

void BST::add(int key)
{
    Node n(key);
    Node* ptr;

    ptr = this->root;
    if (this->root == nullptr)
        this->root = &n;
    else
    {
        while (ptr != nullptr)
        {
            if (n.key <= ptr->key)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }
        ptr = &n;
    }
}

void BST::print()
{

}
