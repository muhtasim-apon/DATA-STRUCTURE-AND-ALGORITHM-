// C++ prgram to print BST in a given range
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

// Function to print nodes
// that lie in the range.
vector<int> printNearNodes(Node *root, int low, int high)
{

    vector<int> ans;

    Node *curr = root;
    while (curr != nullptr)
    {

        // if left child is null, check
        // curr node and move to right node.
        if (curr->left == nullptr)
        {
            if (curr->data >= low && curr->data <= high)
                ans.push_back(curr->data);
            curr = curr->right;
        }
        else
        {

            // Find the inorder predecessor of curr
            Node *pre = curr->left;
            while (pre->right != nullptr && pre->right != curr)
                pre = pre->right;

            // Make curr as the right child of its
            // inorder predecessor and move to
            // left node.
            if (pre->right == nullptr)
            {
                pre->right = curr;
                curr = curr->left;
            }

            // Revert the changes made in the 'if' part to
            // restore the original tree i.e., fix the right
            // child of predecessor
            else
            {
                pre->right = nullptr;
                if (curr->data >= low && curr->data <= high)
                    ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }

    return ans;
}

int main()
{

    // BST
    //       22
    //      /  \
    //    12    30
    //   /  \
    //  8    20
    Node *root = new Node(22);
    root->left = new Node(12);
    root->right = new Node(30);
    root->left->left = new Node(8);
    root->left->right = new Node(20);
    int n1 = 10, n2 = 22;
    vector<int> ans = printNearNodes(root, n1, n2);

    for (auto num : ans)
        cout << num << " ";

    return 0;
}