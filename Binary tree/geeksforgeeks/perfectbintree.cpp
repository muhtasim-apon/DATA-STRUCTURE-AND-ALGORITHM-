// C++ program to check if a
// given binary tree is perfect
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
        left = nullptr;
        right = nullptr;
    }
};

// Function to find depth of tree.
int depth(Node *root)
{
    if (root == nullptr)
        return 0;

    return 1 +
           max(depth(root->left), depth(root->right));
}

// Recursive function which checks if
// tree is perfect or not.
bool isPerfectRecur(Node *root, int d)
{

    // Empty tree is also perfect
    if (root == nullptr)
        return true;

    // If node is leaf, check if it
    // is at depth d.
    if (root->left == nullptr && root->right == nullptr)
        return d == 1;

    // If internal node does not have
    // left or right node, return false.
    if (root->left == nullptr || root->right == nullptr)
        return false;

    // Check left and right subtree
    return isPerfectRecur(root->left, d - 1) &&
           isPerfectRecur(root->right, d - 1);
}

bool isPerfect(Node *root)
{

    // Find depth of tree
    int d = depth(root);

    return isPerfectRecur(root, d);
}

int main()
{

    // Binary tree
    //           10
    //        /     \  
    //      20       30
    //     /  \     /  \
    //   40    50  60   70
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);

    if (isPerfect(root))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    return 0;
}