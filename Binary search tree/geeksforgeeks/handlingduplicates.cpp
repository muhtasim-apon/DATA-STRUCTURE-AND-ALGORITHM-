// C++ program to implement basic operations
// (search, insert, and delete) on a BST that
// handles duplicates by storing count with
// every node

#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int key;
    int count;
    Node *left;
    Node *right;

    Node(int x)
    {
        key = x;
        count = 1;
        left = nullptr;
        right = nullptr;
    }
};

// A utility function to do inorder traversal of BST
void inorder(Node *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->key << "(" << root->count << ") ";
        inorder(root->right);
    }
}

// A utility function to insert a new
// node with given key in BST
Node *insert(Node *node, int key)
{

    // If the tree is empty, return a new node
    if (node == nullptr)
        return new Node(key);

    // If key already exists in BST,
    // increment count and return
    if (key == node->key)
    {
        node->count++;
        return node;
    }

    // Otherwise, recur down the tree
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    // return the (unchanged) node pointer
    return node;
}

// Given a non-empty binary search tree, return
// the node with minimum key value found in that
// tree. Note that the entire tree does not need
// to be searched.
Node *minValueNode(Node *node)
{
    Node *current = node;

    // loop down to find the leftmost leaf
    while (current->left != nullptr)
        current = current->left;

    return current;
}

// Given a binary search tree and a key,
// this function deletes a given key and
// returns root of modified tree
Node *deleteNode(Node *root, int key)
{

    // base case
    if (root == nullptr)
        return root;

    // If the key to be deleted is smaller than the
    // root's key, then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than
    // the root's key, then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    // if key is same as root's key
    else
    {

        // If key is present more than once,
        // simply decrement count and return
        if (root->count > 1)
        {
            root->count--;
            return root;
        }

        // else, delete the node
        // node with only one child or no child
        if (root->left == nullptr)
        {
            Node *curr = root->right;
            delete root;
            return curr;
        }
        else if (root->right == nullptr)
        {
            Node *curr = root->left;
            delete root;
            return curr;
        }

        // node with two children: Get the inorder
        // successor (smallest in the right subtree)
        Node *mn = minValueNode(root->right);

        // Copy the inorder successor's
        // content to this node
        root->key = mn->key;
        root->count = mn->count;

        // To ensure successor gets deleted by
        // deleteNode call, set count to 0.
        mn->count = 0;

        // Delete the inorder successor
        root->right = deleteNode(root->right, mn->key);
    }
    return root;
}

int main()
{

    // Let us create following BST
    //        12(3)
    //       /     \
    //    10(2)     20(1)
    //   /   \
    // 9(1) 11(1)
    Node *root = nullptr;
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 9);
    root = insert(root, 11);
    root = insert(root, 10);
    root = insert(root, 12);
    root = insert(root, 12);

    cout << "Inorder traversal of the given tree " << endl;
    inorder(root);

    cout << "\nDelete 20\n";
    root = deleteNode(root, 20);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);

    cout << "\nDelete 12\n";
    root = deleteNode(root, 12);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);

    cout << "\nDelete 9\n";
    root = deleteNode(root, 9);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);

    return 0;
}