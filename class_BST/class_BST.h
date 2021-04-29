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
    Node* find(Node* root, int key);

    // in-order traversal (ЛКП обход дерева)
    void inorder(Node* node);

public:
    BST();

    void insert(int key);
    Node* search(int key);
    void display();
};
