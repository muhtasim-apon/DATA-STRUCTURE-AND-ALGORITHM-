#include <iostream>
#include <stdlib.h>
#include <queue>
#include <vector>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

node *insertNode(node *root, int key)
{
    if (root == NULL)
    {
        return new node(key);
    }
    if (root->data < key)
    {
        root->right = insertNode(root->right, key);
    }
    else if (root->data >= key)
    {
        root->left = insertNode(root->left, key);
    }
    return root;
}
int count = 0, level = 1;
int height(node *root)
{
    if (root == NULL)
        return 0;
    int h1 = height(root->left);
    int h2 = height(root->right);
    if (h2 - h1 <= 2)
        return 1;
    return 0;
}
int ans(node *root)
{
    if (root == NULL)
        return 0;
    ans(root->left);
    if (height(root) == 1)
        count++;
    ans(root->right);
    return count;
}
int main()
{
    int n;
    cin >> n;
    node *root = NULL;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        root = insertNode(root, arr[i]);
    }
    int ans1 = ans(root);
    cout << ans1;
}
