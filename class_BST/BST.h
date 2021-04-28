#ifndef BST_H
# define BST_H

// Tree node class
class Node
{
private:
    int key;
    Node* left;
    Node* right;

    Node(int key);

    friend class BST;
};

// Tree class
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