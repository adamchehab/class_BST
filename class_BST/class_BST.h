#pragma once

class BST
{
private:
    struct Node
    {
        int key;
        Node* left;
        Node* right;
    };
    Node* root;

    Node* makeEmpty(Node* t);

    Node* insert(int key, Node* root);
    Node* removenode(int x); //
    Node* find(Node* node, int x);
    void inorder(Node* node);

public:
    BST();
    ~BST();

    void insert(int key); 
    bool remove(int x); //
    bool search(int x);
    void display();
};
