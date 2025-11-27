#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int value)
    {
        key = value;
        left = right = nullptr;
    }
};

// Function to find the ceiling of a given
// input in BST. If the input is more than
// the max key in BST, return -1.
int findCeil(Node *root, int input)
{

    // Base case
    if (root == nullptr)
        return -1;

    // We found equal key
    if (root->key == input)
        return root->key;

    // If root's key is smaller,
    // ceil must be in the right subtree
    if (root->key < input)
        return findCeil(root->right, input);

    // Else, either left subtree or
    // root has the ceil value
    int ceil = findCeil(root->left, input);
    return (ceil >= input) ? ceil : root->key;
}

// Driver code
int main()
{
    Node *root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);

    // Testing for values from 0 to 15
    for (int i = 0; i < 16; i++)
        cout << i << " " << findCeil(root, i) << endl;

    return 0;
}