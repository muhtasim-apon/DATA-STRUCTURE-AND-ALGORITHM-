// C++ implementation to check if a
// Binary Tree is complete
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

// Function to check if the binary tree is complete
bool isCompleteBinaryTree(Node *root)
{
    if (root == nullptr)
        return true;

    queue<Node *> q;
    q.push(root);
    bool end = false;

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();

        // Check left child
        if (current->left)
        {
            if (end)
                return false;
            q.push(current->left);
        }
        else
        {

            // If left child is missing,
            // mark the end
            end = true;
        }

        // Check right child
        if (current->right)
        {
            if (end)
                return false;

            q.push(current->right);
        }
        else
        {

            // If right child is missing,
            // mark the end
            end = true;
        }
    }

    return true;
}

int main()
{

    // Representation of Input tree
    //         1
    //        /  \
    //       2    3
    //      / \   /
    //     4   5  6
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    if (isCompleteBinaryTree(root))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}