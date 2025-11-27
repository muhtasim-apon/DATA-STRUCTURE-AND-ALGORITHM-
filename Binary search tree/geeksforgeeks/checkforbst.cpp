#include <iostream>
#include <climits>
using namespace std;

// Node structure
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = right = nullptr;
    }
};

// Helper function to check if a tree is BST within a given range
bool isBSTUtil(Node *node, int min, int max)
{
    if (node == nullptr)
        return true;

    // If the current node's data
    // is not in the valid range, return false
    if (node->data < min || node->data > max)
        return false;

    // Recursively check the left and
    // right subtrees with updated ranges
    return isBSTUtil(node->left, min, node->data - 1) &&
           isBSTUtil(node->right, node->data + 1, max);
}

// Function to check if the entire binary tree is a BST
bool isBST(Node *root)
{
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main()
{

    // Create a sample binary tree
    //     10
    //    /  \
    //   5    20
    //        / \
    //       9   25

    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(9);
    root->right->right = new Node(25);

    if (isBST(root))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
