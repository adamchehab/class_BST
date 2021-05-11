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

    Node* makeEmpty(Node* node);
    Node* insertNode(int key, Node* root);
    Node* findMin(Node* node);
    Node* deleteNode(Node* node, int x);
    Node* findNode(Node* node, int x);
    void inorder(Node* node);

public:
    BST();
    ~BST();

    void insert(int x); 
    bool remove(int x);
    bool search(int x);
    void display();
};
