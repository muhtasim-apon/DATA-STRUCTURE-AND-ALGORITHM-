// C++ program to
// check if two Nodes are Cousins
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};

// Recursive function to check if two Nodes are siblings
bool isSibling(Node *root, int a, int b)
{

    // Base case
    if (root == NULL)
        return false;

    if (root->left != nullptr && root->right != nullptr &&
        root->left->data == a && root->right->data == b)
        return true;

    if (root->left != nullptr && root->right != nullptr &&
        root->left->data == b && root->right->data == a)
        return true;

    return isSibling(root->left, a, b) ||
           isSibling(root->right, a, b);
}

// Recursive function to find level of Node with data = value in a
// binary tree
int level(Node *root, int value, int lev)
{

    // base cases
    if (root == NULL)
        return 0;
    if (root->data == value)
        return lev;

    // Return level if Node is present in left subtree
    int l = level(root->left, value, lev + 1);
    if (l != 0)
        return l;

    // Else search in right subtree
    return level(root->right, value, lev + 1);
}

// Returns true if a and b are cousins, otherwise false
bool isCousins(Node *root, int a, int b)
{

    // 1. The two Nodes should be on the same level in the
    // binary tree.
    // 2. The two Nodes should not be siblings (means that
    // they should
    // not have the same parent Node).

    if (a == b)
        return false;

    int aLevel = level(root, a, 1);
    int bLevel = level(root, b, 1);

    // if a or b does not exists in the tree
    if (aLevel == 0 || bLevel == 0)
        return false;

    if (aLevel == bLevel && !isSibling(root, a, b))
        return true;
    else
        return false;
}

int main()
{

    // create hard coded tree
    //       1
    //     /   \ 
    //    2     3
    //   /       \
    //  5         4
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);

    int a = 4, b = 5;

    if (isCousins(root, a, b))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}