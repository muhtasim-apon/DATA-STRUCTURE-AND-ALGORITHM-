#include <iostream>
#include <stdlib.h>
#include <queue>

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

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (!temp->left && key != 1)
        {
            temp->left = new node(key);
            break;
        }
        else
            q.push(temp->left);
        if (!temp->right && key != 1)
        {
            temp->right = new node(key);
            break;
        }
        else
            q.push(temp->right);
    }
    return root;
}
int height(node *root)
{
    if (root == NULL)
        return 0;
    int h1 = height(root->left);
    int h2 = height(root->right);
    return max(h1, h2) + 1;
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
    int ans = height(root);
    cout << ans << "\n";
}
