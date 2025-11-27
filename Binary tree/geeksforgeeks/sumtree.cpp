// C++ program to check if Binary tree
// is sum tree or not
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

// A utility function to get the sum
// of values in tree
int sum(Node *root)
{
    if (root == NULL)
        return 0;

    return sum(root->left) + root->data +
           sum(root->right);
}

// Returns 1 if sum property holds for
// the given node and both of its children
bool isSumTree(Node *root)
{
    int ls, rs;

    // If root is NULL or it's a leaf
    // node then return true
    if (root == nullptr ||
        (root->left == nullptr &&
         root->right == nullptr))
        return true;

    // Get sum of nodes in left and
    // right subtrees
    ls = sum(root->left);
    rs = sum(root->right);

    // If the root and both of its
    // children satisfy the property
    // return true else false
    if ((root->data == ls + rs) &&
        isSumTree(root->left) &&
        isSumTree(root->right))
        return true;

    return false;
}

int main()
{

    // create hard coded tree
    //       26
    //      /  \
    //     10   3
    //    / \    \
    //   4  6     3
    Node *root = new Node(26);
    root->left = new Node(10);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->right = new Node(3);

    if (isSumTree(root))
        cout << "True";
    else
        cout << "False";

    return 0;
}