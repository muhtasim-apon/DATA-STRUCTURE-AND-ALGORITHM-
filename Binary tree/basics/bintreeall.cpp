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

// ====================== Basic Operations ======================

// Check if tree is empty
bool isEmpty(Node *root)
{
    return root == nullptr;
}

// Count total nodes
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

// Height of tree
int height(Node *root)
{
    if (!root)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

// Search a value
bool search(Node *root, int key)
{
    if (!root)
        return false;
    if (root->data == key)
        return true;
    return search(root->left, key) || search(root->right, key);
}

// Level-wise insert (first empty position)
Node *insert(Node *root, int val)
{
    Node *newNode = new Node(val);
    if (!root)
        return newNode;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (!temp->left)
        {
            temp->left = newNode;
            break;
        }
        else
            q.push(temp->left);
        if (!temp->right)
        {
            temp->right = newNode;
            break;
        }
        else
            q.push(temp->right);
    }
    return root;
}

// Delete a node (replace with deepest rightmost)
Node *deleteNode(Node *root, int key)
{
    if (!root)
        return nullptr;
    if (!root->left && !root->right)
    {
        if (root->data == key)
        {
            delete root;
            return nullptr;
        }
        else
            return root;
    }

    queue<Node *> q;
    q.push(root);
    Node *target = nullptr;
    Node *temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp->data == key)
            target = temp;
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }

    if (target)
    {
        int x = temp->data; // deepest node
        delete temp;        // free memory
        target->data = x;
        // Remove deepest node properly
        queue<Node *> qq;
        qq.push(root);
        while (!qq.empty())
        {
            Node *t = qq.front();
            qq.pop();
            if (t->left)
            {
                if (t->left->data == x)
                {
                    t->left = nullptr;
                    break;
                }
                else
                    qq.push(t->left);
            }
            if (t->right)
            {
                if (t->right->data == x)
                {
                    t->right = nullptr;
                    break;
                }
                else
                    qq.push(t->right);
            }
        }
    }
    return root;
}

// ====================== Traversals ======================

// Preorder
void preorder(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Inorder
void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Postorder
void postorder(Node *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Level-order
void levelOrder(Node *root)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
}

// Reverse level-order
void reverseLevelOrder(Node *root)
{
    if (!root)
        return;
    queue<Node *> q;
    stack<int> s;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        s.push(temp->data);
        if (temp->right)
            q.push(temp->right);
        if (temp->left)
            q.push(temp->left);
    }
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

// Spiral / Zigzag traversal
void zigzagTraversal(Node *root)
{
    if (!root)
        return;
    stack<Node *> currentLevel, nextLevel;
    currentLevel.push(root);
    bool leftToRight = true;
    while (!currentLevel.empty())
    {
        Node *temp = currentLevel.top();
        currentLevel.pop();
        cout << temp->data << " ";
        if (leftToRight)
        {
            if (temp->left)
                nextLevel.push(temp->left);
            if (temp->right)
                nextLevel.push(temp->right);
        }
        else
        {
            if (temp->right)
                nextLevel.push(temp->right);
            if (temp->left)
                nextLevel.push(temp->left);
        }
        if (currentLevel.empty())
        {
            leftToRight = !leftToRight;
            swap(currentLevel, nextLevel);
        }
    }
}

// Print leaf nodes
void printLeaves(Node *root)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        cout << root->data << " ";
        return;
    }
    printLeaves(root->left);
    printLeaves(root->right);
}

// Print nodes at level k
void printLevel(Node *root, int k)
{
    if (!root)
        return;
    if (k == 1)
    {
        cout << root->data << " ";
        return;
    }
    printLevel(root->left, k - 1);
    printLevel(root->right, k - 1);
}

// Sum of all nodes
int sumNodes(Node *root)
{
    if (!root)
        return 0;
    return root->data + sumNodes(root->left) + sumNodes(root->right);
}

// Maximum / Minimum
int maxNode(Node *root)
{
    if (!root)
        return INT_MIN;
    return max(root->data, max(maxNode(root->left), maxNode(root->right)));
}

int minNode(Node *root)
{
    if (!root)
        return INT_MAX;
    return min(root->data, min(minNode(root->left), minNode(root->right)));
}

// ====================== Advanced Operations ======================

// Mirror tree
void mirror(Node *root)
{
    if (!root)
        return;
    swap(root->left, root->right);
    mirror(root->left);
    mirror(root->right);
}

// Check if two trees are identical
bool identical(Node *a, Node *b)
{
    if (!a && !b)
        return true;
    if (!a || !b)
        return false;
    return (a->data == b->data) && identical(a->left, b->left) && identical(a->right, b->right);
}

// Lowest Common Ancestor
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
    return (l ? l : r);
}

// Diameter of tree
int diameter(Node *root, int &height)
{
    if (!root)
    {
        height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int ldiam = diameter(root->left, lh);
    int rdiam = diameter(root->right, rh);
    height = 1 + max(lh, rh);
    return max({ldiam, rdiam, lh + rh + 1});
}

// Check symmetric
bool isMirror(Node *a, Node *b)
{
    if (!a && !b)
        return true;
    if (!a || !b)
        return false;
    return (a->data == b->data) && isMirror(a->left, b->right) && isMirror(a->right, b->left);
}

bool isSymmetric(Node *root)
{
    return !root || isMirror(root->left, root->right);
}

// ====================== UI Menu ======================

int main()
{
    Node *root = nullptr;
    int choice, val, k, n1, n2;
    while (true)
    {
        cout << "\nBinary Tree Operations Menu:\n";
        cout << "1. Insert Node\n2. Delete Node\n3. Check Empty\n4. Count Nodes\n5. Count Leaves\n";
        cout << "6. Count Non-Leaves\n7. Height\n8. Search\n9. Preorder\n10. Inorder\n11. Postorder\n";
        cout << "12. Level-order\n13. Reverse Level-order\n14. Zigzag\n15. Print Leaves\n16. Print Level k\n";
        cout << "17. Sum of Nodes\n18. Max Node\n19. Min Node\n20. Mirror\n21. Identical\n22. LCA\n";
        cout << "23. Diameter\n24. Check Symmetric\n0. Exit\nEnter choice: ";
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
            cout << (isEmpty(root) ? "Empty" : "Not Empty") << "\n";
            break;
        case 4:
            cout << "Total Nodes: " << countNodes(root) << "\n";
            break;
        case 5:
            cout << "Leaf Nodes: " << countLeaves(root) << "\n";
            break;
        case 6:
            cout << "Non-leaf Nodes: " << countNonLeaves(root) << "\n";
            break;
        case 7:
            cout << "Height: " << height(root) << "\n";
            break;
        case 8:
            cout << "Search value: ";
            cin >> val;
            cout << (search(root, val) ? "Found" : "Not Found") << "\n";
            break;
        case 9:
            preorder(root);
            cout << "\n";
            break;
        case 10:
            inorder(root);
            cout << "\n";
            break;
        case 11:
            postorder(root);
            cout << "\n";
            break;
        case 12:
            levelOrder(root);
            cout << "\n";
            break;
        case 13:
            reverseLevelOrder(root);
            cout << "\n";
            break;
        case 14:
            zigzagTraversal(root);
            cout << "\n";
            break;
        case 15:
            printLeaves(root);
            cout << "\n";
            break;
        case 16:
            cout << "Enter level k: ";
            cin >> k;
            printLevel(root, k);
            cout << "\n";
            break;
        case 17:
            cout << "Sum: " << sumNodes(root) << "\n";
            break;
        case 18:
            cout << "Max: " << maxNode(root) << "\n";
            break;
        case 19:
            cout << "Min: " << minNode(root) << "\n";
            break;
        case 20:
            mirror(root);
            cout << "Tree mirrored.\n";
            break;
        case 21:
        {
            cout << "Enter second tree root value: ";
            cin >> val;
            Node *root2 = new Node(val); // Example, can extend to build full tree
            cout << (identical(root, root2) ? "Identical" : "Not Identical") << "\n";
            break;
        }
        case 22:
            cout << "Enter two nodes for LCA: ";
            cin >> n1 >> n2;
            {
                Node *ans = LCA(root, n1, n2);
                cout << (ans ? ans->data : -1) << "\n";
            }
            break;
        case 23:
        {
            int h = 0;
            cout << "Diameter: " << diameter(root, h) << "\n";
        }
        break;
        case 24:
            cout << (isSymmetric(root) ? "Symmetric" : "Not Symmetric") << "\n";
            break;
        default:
            cout << "Invalid Choice\n";
        }
    }

    return 0;
}
