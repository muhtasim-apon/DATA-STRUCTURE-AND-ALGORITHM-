// C++ program to find Sum Of All Elements smaller
// than or equal to Kth Smallest Element In BST
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

// Recursive function to calculate the sum of the
// first k smallest elements
void calculateSum(Node *root, int &k, int &ans)
{

    if (root->left != nullptr)
    {
        calculateSum(root->left, k, ans);
    }

    if (k > 0)
    {
        ans += root->data;
        k--;
    }
    else
    {
        return;
    }

    if (root->right != nullptr)
    {
        calculateSum(root->right, k, ans);
    }
}

// Function to find the sum of the first
// k smallest elements
int sum(Node *root, int k)
{

    int ans = 0;
    calculateSum(root, k, ans);
    return ans;
}

int main()
{

    // Input BST
    //         8
    //       /   \
    //      7     10
    //    /      /  \
    //   2      9    13
    Node *root = new Node(8);
    root->left = new Node(7);
    root->right = new Node(10);
    root->left->left = new Node(2);
    root->right->left = new Node(9);
    root->right->right = new Node(13);

    int k = 3;
    cout << sum(root, k) << "\n";

    return 0;
}