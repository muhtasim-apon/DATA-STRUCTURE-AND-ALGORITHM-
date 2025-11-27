#include <iostream>
using namespace std;

// Node structure
class Node
{
public:
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

bool isIdentical(Node *r1, Node *r2)
{

    // If both trees are empty, they are identical
    if (r1 == nullptr && r2 == nullptr)
        return true;

    // If only one tree is empty, they are not identical
    if (r1 == nullptr || r2 == nullptr)
        return false;

    // Check if the root data is the same and
    // recursively check for the left and right subtrees
    return (r1->data == r2->data) &&
           isIdentical(r1->left, r2->left) &&
           isIdentical(r1->right, r2->right);
}

int main()
{

    // Representation of input binary tree 1
    //        1
    //       / \
    //      2   3
    //     /
    //    4

    Node *r1 = new Node(1);
    r1->left = new Node(2);
    r1->right = new Node(3);
    r1->left->left = new Node(4);

    // Representation of input binary tree 2
    //        1
    //       / \
    //      2   3
    //     /
    //    4
    Node *r2 = new Node(1);
    r2->left = new Node(2);
    r2->right = new Node(3);
    r2->left->left = new Node(4);

    if (isIdentical(r1, r2))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}