#ifndef BST_H
# define BST_H

class Node
{
public:
    int key;
    Node* left;
    Node* right;

    Node(int key);
};

class BST
{
private:
    Node* root;

public:
    BST();
    void add(int key);
    void print();
};

#endif