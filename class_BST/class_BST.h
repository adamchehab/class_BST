#pragma once
using namespace std;

template <typename T>
class BST
{
private:
    template <typename T>
    struct Node
    {
        T key;
        Node* left;
        Node* right;
    };
    Node<T>* root;

    Node<T>* makeEmpty(Node<T>* node);
    Node<T>* insertNode(T x, Node<T>* root);
    Node<T>* findMin(Node<T>* node);
    Node<T>* deleteNode(Node<T>* node, T x);
    Node<T>* findNode(Node<T>* node, T x);
    void inorder(Node<T>* node);

public:
    BST();
    ~BST();

    void insert(T x); 
    bool remove(T x);
    bool search(T x);
    void display();
};

template <typename T>
BST<T>::BST()
{
    root = NULL;
}

template <typename T>
BST<T>::~BST()
{
    root = makeEmpty(root);
}

template <typename T>
BST<T>::Node<T>* BST<T>::makeEmpty(Node<T>* node)
{
    if (node == NULL)
        return NULL;
    {
        makeEmpty(node->left);
        makeEmpty(node->right);
        delete node;
    }
    return NULL;
}

template <typename T>
BST<T>::Node<T>* BST<T>::insertNode(T x, Node<T>* node)
{
    if (node == NULL)
    {
        node = new Node<T>;
        node->key = x;
        node->left = NULL;
        node->right = NULL;
    }
    // ??? < or <= what do we do if value is already in the three
    else if (x <= node->key)
        node->left = insertNode(x, node->left);
    else if (x > node->key)
        node->right = insertNode(x, node->right);
    return (node);
}

template <typename T>
BST<T>::Node<T>* BST<T>::findMin(Node<T>* node)
{
    if (node->left != NULL)
        node = findMin(node->left);
    return node;
}

template <typename T>
BST<T>::Node<T>* BST<T>::deleteNode(Node<T>* node, T x)
{
    Node<T>* temp;
    if (node == NULL)
        return node;
    else if (x < node->key)
        node->left = deleteNode(node->left, x);
    else if (x > node->key)
        node->right = deleteNode(node->right, x);
    else if (node->left && node->right)
    {
        temp = findMin(node->right);
        node->key = temp->key;
        node->right = deleteNode(node->right, node->key);
    }
    else
    {
        temp = node;
        if (node->left == NULL)
            node = node->right;
        else if (node->right == NULL)
            node = node->left;
        delete temp;
    }
    return node;
}

template <typename T>
BST<T>::Node<T>* BST<T>::findNode(Node<T>* node, T x)
{
    if (node == NULL)
        return NULL;
    else if (x < node->key)
        return findNode(node->left, x);
    else if (x > node->key)
        return findNode(node->right, x);
    else
        return node;
}

template <typename T>
void BST<T>::inorder(Node<T>* node)
{
    if (node == NULL)
        return;
    inorder(node->left);
    cout << node->key << " ";
    inorder(node->right);
}

template <typename T>
void BST<T>::insert(T x)
{
    root = insertNode(x, root);
}

template <typename T>
bool BST<T>::remove(T x)
{
    root = deleteNode(root, x);
    return ((search(x) == false) ? false : true);
}

template <typename T>
bool BST<T>::search(T x)
{
    return ((findNode(root, x) == NULL) ? 0 : 1);
}

template <typename T>
void BST<T>::display()
{
    cout << "Tree: ";
    inorder(root);
    cout << endl;
}
