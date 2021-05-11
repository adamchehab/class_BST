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

    Node* insert(int key, Node* root);
    Node* find(Node* node, int x);
    Node* makeEmpty(Node* t);
    

    // ЛКП (обход дерева)
    void inorder(Node* node);

public:
    BST();
    ~BST();

    void insert(int key); 
    bool search(int x);
    void display();
};
