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
int ans(node *root, int start, int end)
{
    if (root == NULL)
        return 0;
    queue<node *> q;
    if (root)
        q.push(root);
    int level = 1;
    if (level >= start && level <= end)
    {
        count += 1;
    }
    while (!q.empty())
    {
        int size = q.size();
        if (level >= start && level <= end)
            count += q.size();
        for (int i = 0; i < size; i++)
        {
            node *temp = q.front();
            q.pop();
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        level++;
    }
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
    int start, end;
    cin >> start >> end;
    int ans1 = ans(root, start, end);
    cout << ans1;
}
