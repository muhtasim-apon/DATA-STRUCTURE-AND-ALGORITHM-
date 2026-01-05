#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left, *right;
    Node(int v) : val(v), left(NULL), right(NULL) {}
};

Node *insertBST(Node *root, int x)
{
    if (!root)
        return new Node(x);
    if (x < root->val)
        root->left = insertBST(root->left, x);
    else
        root->right = insertBST(root->right, x);
    return root;
}

// MANUAL STACK
struct Stack
{
    Node *arr[200005];
    int top;
    Stack() { top = -1; }
    inline void push(Node *x) { arr[++top] = x; }
    inline Node *pop() { return arr[top--]; }
    inline Node *peek() { return arr[top]; }
    inline bool empty() { return top == -1; }
};

void pushLeft(Node *root, Stack &st)
{
    while (root)
    {
        st.push(root);
        root = root->left;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n1, n2;
    cin >> n1;

    Node *root1 = NULL;
    for (int i = 0; i < n1; i++)
    {
        int x;
        cin >> x;
        root1 = insertBST(root1, x);
    }

    cin >> n2;
    Node *root2 = NULL;
    for (int i = 0; i < n2; i++)
    {
        int x;
        cin >> x;
        root2 = insertBST(root2, x);
    }

    Stack s1, s2;
    pushLeft(root1, s1);
    pushLeft(root2, s2);

    bool first = true;

    while (!s1.empty() || !s2.empty())
    {
        Node *curr;

        if (s2.empty() || (!s1.empty() && s1.peek()->val <= s2.peek()->val))
        {
            curr = s1.pop();
            pushLeft(curr->right, s1);
        }
        else
        {
            curr = s2.pop();
            pushLeft(curr->right, s2);
        }

        if (!first)
            cout << " ";
        cout << curr->val;
        first = false;
    }

    cout << '\n';

    return 0;
}
