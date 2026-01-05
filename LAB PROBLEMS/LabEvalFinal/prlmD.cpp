#include <bits/stdc++.h>
using namespace std;

struct tree2
{
    int val;
    tree2 *left, *right;
    tree2(int v) : val(v), left(NULL), right(NULL) {}
};

tree2 *insert2(tree2 *root, int v)
{
    if (!root)
        return new tree2(v);
    if (v < root->val)
        root->left = insert2(root->left, v);
    else
        root->right = insert2(root->right, v);
    return root;
}

struct tree1
{
    int key;
    tree2 *secondary;
    tree1 *left, *right;
    tree1(int k) : key(k), secondary(NULL), left(NULL), right(NULL) {}
};

tree1 *insert1(tree1 *root, int key, int v)
{
    if (!root)
    {
        tree1 *t = new tree1(key);
        t->secondary = insert2(t->secondary, v);
        return t;
    }
    if (key < root->key)
        root->left = insert1(root->left, key, v);
    else if (key > root->key)
        root->right = insert1(root->right, key, v);
    else
        root->secondary = insert2(root->secondary, v);
    return root;
}

void printtree(tree2 *root)
{
    stack<tree2 *> st;
    tree2 *current = root;
    int f = 1;
    while (current || !st.empty())
    {
        while (current)
        {
            st.push(current);
            current = current->left;
        }
        current = st.top();
        st.pop();
        if (!f)
            cout << " ";
        cout << current->val;
        f = 0;
        current = current->right;
    }
}

void traversetree1(tree1 *root)
{
    stack<tree1 *> st;
    tree1 *current = root;
    while (current || !st.empty())
    {
        while (current)
        {
            st.push(current);
            current = current->left;
        }
        current = st.top();
        st.pop();
        printtree(current->secondary);
        cout << "\n";
        current = current->right;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    tree1 *root = NULL;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        int m = x % k;
        root = insert1(root, m, x);
    }
    traversetree1(root);
}
