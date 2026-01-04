#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

// ---------------- Basic BST Operations ----------------

// Check empty
bool isEmpty(Node *root) { return root == nullptr; }

// Insert
Node *insert(Node *root, int val)
{
    if (!root)
        return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    return root;
}

// Search
bool search(Node *root, int val)
{
    if (!root)
        return false;
    if (root->data == val)
        return true;
    if (val < root->data)
        return search(root->left, val);
    else
        return search(root->right, val);
}

// Min / Max
Node *findMin(Node *root)
{
    while (root && root->left)
        root = root->left;
    return root;
}
Node *findMax(Node *root)
{
    while (root && root->right)
        root = root->right;
    return root;
}

// Delete node
Node *deleteNode(Node *root, int key)
{
    if (!root)
        return nullptr;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        if (!root->left)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Count nodes
int countNodes(Node *root)
{
    if (!root)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Count leaf nodes
int countLeaves(Node *root)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

// Count non-leaf nodes
int countNonLeaves(Node *root)
{
    if (!root || (!root->left && !root->right))
        return 0;
    return 1 + countNonLeaves(root->left) + countNonLeaves(root->right);
}

// Height
int height(Node *root)
{
    if (!root)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

// Sum of nodes
int sumNodes(Node *root)
{
    if (!root)
        return 0;
    return root->data + sumNodes(root->left) + sumNodes(root->right);
}

// ---------------- Traversals ----------------

void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void levelOrder(Node *root)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *t = q.front();
        q.pop();
        cout << t->data << " ";
        if (t->left)
            q.push(t->left);
        if (t->right)
            q.push(t->right);
    }
}

void reverseLevelOrder(Node *root)
{
    if (!root)
        return;
    queue<Node *> q;
    stack<int> s;
    q.push(root);
    while (!q.empty())
    {
        Node *t = q.front();
        q.pop();
        s.push(t->data);
        if (t->right)
            q.push(t->right);
        if (t->left)
            q.push(t->left);
    }
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

// ---------------- Properties ----------------

// Mirror
void mirror(Node *root)
{
    if (!root)
        return;
    swap(root->left, root->right);
    mirror(root->left);
    mirror(root->right);
}

// Identical
bool identical(Node *a, Node *b)
{
    if (!a && !b)
        return true;
    if (!a || !b)
        return false;
    return a->data == b->data && identical(a->left, b->left) && identical(a->right, b->right);
}

// LCA
Node *LCA(Node *root, int n1, int n2)
{
    if (!root)
        return nullptr;
    if (root->data == n1 || root->data == n2)
        return root;
    Node *l = LCA(root->left, n1, n2);
    Node *r = LCA(root->right, n1, n2);
    if (l && r)
        return root;
    return l ? l : r;
}

// Diameter
int diameter(Node *root, int &h)
{
    if (!root)
    {
        h = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int ldiam = diameter(root->left, lh);
    int rdiam = diameter(root->right, rh);
    h = 1 + max(lh, rh);
    return max({ldiam, rdiam, lh + rh + 1});
}

// Symmetric check
bool isMirror(Node *a, Node *b)
{
    if (!a && !b)
        return true;
    if (!a || !b)
        return false;
    return a->data == b->data && isMirror(a->left, b->right) && isMirror(a->right, b->left);
}
bool isSymmetric(Node *root) { return !root || isMirror(root->left, root->right); }

// ---------------- Advanced ----------------

// Kth smallest
void kthSmallestUtil(Node *root, int &k, int &res)
{
    if (!root)
        return;
    kthSmallestUtil(root->left, k, res);
    if (--k == 0)
    {
        res = root->data;
        return;
    }
    kthSmallestUtil(root->right, k, res);
}
int kthSmallest(Node *root, int k)
{
    int res = -1;
    kthSmallestUtil(root, k, res);
    return res;
}

// ---------------- UI Menu ----------------

int main()
{
    Node *root = nullptr;
    int choice, val, k, n1, n2;
    while (true)
    {
        cout << "\nBST Operations Menu:\n";
        cout << "1.Insert 2.Delete 3.Search 4.Min 5.Max 6.Count Nodes 7.Count Leaves 8.Count Non-Leaves 9.Height\n";
        cout << "10.Sum 11.Inorder 12.Preorder 13.Postorder 14.Level-order 15.Reverse Level-order 16.Mirror\n";
        cout << "17.Identical 18.LCA 19.Diameter 20.Symmetric 21.Kth Smallest 0.Exit\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            exit(0);
        case 1:
            cout << "Enter value: ";
            cin >> val;
            root = insert(root, val);
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> val;
            root = deleteNode(root, val);
            break;
        case 3:
            cout << "Enter value to search: ";
            cin >> val;
            cout << (search(root, val) ? "Found" : "Not Found") << "\n";
            break;
        case 4:
        {
            Node *mn = findMin(root);
            cout << (mn ? mn->data : -1) << "\n";
        }
        break;
        case 5:
        {
            Node *mx = findMax(root);
            cout << (mx ? mx->data : -1) << "\n";
        }
        break;
        case 6:
            cout << countNodes(root) << "\n";
            break;
        case 7:
            cout << countLeaves(root) << "\n";
            break;
        case 8:
            cout << countNonLeaves(root) << "\n";
            break;
        case 9:
            cout << height(root) << "\n";
            break;
        case 10:
            cout << sumNodes(root) << "\n";
            break;
        case 11:
            inorder(root);
            cout << "\n";
            break;
        case 12:
            preorder(root);
            cout << "\n";
            break;
        case 13:
            postorder(root);
            cout << "\n";
            break;
        case 14:
            levelOrder(root);
            cout << "\n";
            break;
        case 15:
            reverseLevelOrder(root);
            cout << "\n";
            break;
        case 16:
            mirror(root);
            cout << "Tree mirrored\n";
            break;
        case 17:
        {
            cout << "Enter second tree root value: ";
            cin >> val;
            Node *root2 = new Node(val);
            cout << (identical(root, root2) ? "Identical" : "Not Identical") << "\n";
            break;
        }
        case 18:
            cout << "Enter two nodes for LCA: ";
            cin >> n1 >> n2;
            {
                Node *ans = LCA(root, n1, n2);
                cout << (ans ? ans->data : -1) << "\n";
            }
            break;
        case 19:
        {
            int h = 0;
            cout << "Diameter: " << diameter(root, h) << "\n";
        }
        break;
        case 20:
            cout << (isSymmetric(root) ? "Symmetric" : "Not Symmetric") << "\n";
            break;
        case 21:
            cout << "Enter k: ";
            cin >> k;
            cout << "Kth smallest: " << kthSmallest(root, k) << "\n";
            break;
        default:
            cout << "Invalid Choice\n";
        }
    }
    return 0;
}
