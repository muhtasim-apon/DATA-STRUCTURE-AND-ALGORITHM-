// C++ program to find the second largest element
//  in BST using reverse inorder traversal
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
        left = right = nullptr;
    }
};

// Helper function to find the second largest element
void reverseInorder(Node *root, int &count, int &result)
{

    // Base case: if root is null or we have already
    // found the second largest
    if (root == nullptr || count >= 2)
    {
        return;
    }

    // Traverse the right subtree first (reverse inorder)
    reverseInorder(root->right, count, result);

    // Increment the count of visited nodes
    count++;

    // If count becomes 2, then this is
    // the second largest element
    if (count == 2)
    {
        result = root->data;
        return;
    }

    // Traverse the left subtree
    reverseInorder(root->left, count, result);
}

// Function to find the second largest element in BST
int findSecondLargest(Node *root)
{
    int count = 0;
    int result = -1;

    // Start reverse inorder traversal
    reverseInorder(root, count, result);

    return result;
}

int main()
{

    // Representation of the input BST:
    //              7
    //             / \
    //            4   8
    //           / \   
    //          3   5
    Node *root = new Node(7);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(3);
    root->left->right = new Node(5);

    int secondLargest = findSecondLargest(root);

    cout << secondLargest << endl;

    return 0;
}