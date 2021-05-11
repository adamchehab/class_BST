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
    Node* insertNode(int key, Node* root);
    Node* findMin(Node* node);
    Node* deleteNode(Node* node, int n);
    Node* findNode(Node* node, int x);
    void inorder(Node* node);

public:
    BST();
    ~BST();

    void insert(int key); 
    bool remove(int x);
    bool search(int x);
    void display();
};
