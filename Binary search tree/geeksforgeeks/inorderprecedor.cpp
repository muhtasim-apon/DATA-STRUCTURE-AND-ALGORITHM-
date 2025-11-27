// C++ Program to find Inorder Successor in
// Binary Search Tree
#include <bits/stdc++.h>
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

// Function to find the rightmost (maximum)
// node in the left subtree
Node *rightmost(Node *node)
{
    while (node->right != nullptr)
    {
        node = node->right;
    }
    return node;
}

Node *getPred(Node *root, int target)
{

    // No Inorder predecessor
    if (root == nullptr)
        return nullptr;

    // Use BST properties to search for the
    // target and predecessor
    Node *pred = nullptr;
    Node *curr = root;
    while (curr != nullptr)
    {

        // If the current node's data is less than the target,
        // it is a potential predecessor
        if (target > curr->data)
        {
            pred = curr;
            curr = curr->right;
        }

        // If greater, move to the left child
        else if (target < curr->data)
        {
            curr = curr->left;
        }

        // If equal
        else
        {

            // If the left subtree of target node exists
            // then predecessor will be right most node
            // of the left subtree.
            if (curr->left != nullptr)
            {
                return rightmost(curr->left);
            }

            // Otherwise, the predecessor has already
            // been stored in the pred variable
            break;
        }
    }

    return pred;
}

int main()
{

    // Construct a BST
    //            20
    //          /    \
    //         8      22
    //       /   \
    //      4    12
    //          /  \
    //         10   14
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    int target = 12;
    Node *pred = getPred(root, target);
    if (pred != nullptr)
        cout << pred->data;
    else
        cout << "null";
    return 0;
}