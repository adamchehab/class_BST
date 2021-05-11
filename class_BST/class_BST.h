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
    Node* makeEmpty(Node* t);

    // ��� (����� ������)
    void inorder(Node* node);

public:
    BST();
    ~BST();

    void insert(int key);
    void display();
};
