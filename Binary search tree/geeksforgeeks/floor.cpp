// C++ implementation to find floor of given
// number x in BST
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

// This function is used to find floor
// of given number x
int floor(Node *root, int x)
{

    // Base case: return -1 if no floor found
    if (root == nullptr)
    {
        return -1;
    }

    // If the root's data is equal to x,
    // we've found the floor
    if (root->data == x)
    {
        return root->data;
    }

    // If root's data is greater than x,
    // search in the left subtree
    if (root->data > x)
    {
        return floor(root->left, x);
    }

    // Else, search in the right subtree
    // and compare with current root
    int floorValue = floor(root->right, x);

    // If the right subtree returns
    // a valid floor, return that
    // Otherwise, return the current root's data
    return (floorValue <= x && floorValue != -1)
               ? floorValue
               : root->data;
}

int main()
{

    // Representation of the given tree
    //       10
    //       / \
    //      5  15
    //         / \
    //        12 30
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->right->left = new Node(12);
    root->right->right = new Node(30);

    int x = 14;
    cout << floor(root, x) << endl;
    return 0;
}