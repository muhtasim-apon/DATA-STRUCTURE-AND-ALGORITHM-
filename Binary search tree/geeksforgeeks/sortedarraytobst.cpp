#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Node structure
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

// Function to get Height
int getHeight(Node *root, int h)
{
    if (root == nullptr)
        return h - 1;
    return max(getHeight(root->left, h + 1), getHeight(root->right, h + 1));
}

// Print level order
void levelOrder(Node *root)
{
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    int lastLevel = 0;

    // function to get the height of tree
    int height = getHeight(root, 0);

    // printing the level order of tree
    while (!q.empty())
    {
        auto top = q.front();
        q.pop();
        Node *node = top.first;
        int lvl = top.second;

        if (lvl > lastLevel)
        {
            cout << " ";
            lastLevel = lvl;
        }

        // all levels are printed
        if (lvl > height)
            break;

        if (node->data != -1)
            cout << node->data << " ";

        // printing null node
        else
            cout << "N ";

        // null node has no children
        if (node->data == -1)
            continue;

        if (node->left == nullptr)
            q.push({new Node(-1), lvl + 1});
        else
            q.push({node->left, lvl + 1});

        if (node->right == nullptr)
            q.push({new Node(-1), lvl + 1});
        else
            q.push({node->right, lvl + 1});
    }
}

// Recursive Function to Create BST
Node *sortedArrayToBSTRecur(vector<int> &arr, int start, int end)
{
    if (start > end)
        return nullptr;

    int mid = start + (end - start) / 2;
    Node *root = new Node(arr[mid]);

    // Divide from middle element
    root->left = sortedArrayToBSTRecur(arr, start, mid - 1);
    root->right = sortedArrayToBSTRecur(arr, mid + 1, end);

    return root;
}

// Function which return BST
Node *sortedArrayToBST(vector<int> &arr)
{
    return sortedArrayToBSTRecur(arr, 0, arr.size() - 1);
}

int main()
{
    vector<int> arr = {1, 5, 9, 14, 23, 27};
    Node *root = sortedArrayToBST(arr);
    levelOrder(root);
    return 0;
}