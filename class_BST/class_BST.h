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
    Node* findMinimum(Node* rootPtr);           //
    Node* deleteNode(Node* rootPtr, int n);    //
    Node* find(Node* node, int x);
    void inorder(Node* node);

public:
    BST();
    ~BST();

    void insert(int key); 
    void remove(int x); //
    bool search(int x);
    void display();
};
