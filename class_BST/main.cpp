#include <iostream>
#include "class_BST.h"
using namespace std;

int main()
{
    BST bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(4);
    bst.display();
    cout << bst.search(3) << endl;

    return 0;
}