#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;

    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

// ------------------------ INSERT ------------------------
Node *insertNode(Node *root, int key)
{
    if (root == NULL)
        return new Node(key);

    if (key < root->key)
        root->left = insertNode(root->left, key);
    else if (key > root->key)
        root->right = insertNode(root->right, key);

    return root;
}

// ------------------------ SEARCH ------------------------
bool searchNode(Node *root, int key)
{
    if (root == NULL)
        return false;
    if (root->key == key)
        return true;

    if (key < root->key)
        return searchNode(root->left, key);
    else
        return searchNode(root->right, key);
}

// ------------------------ FIND MIN ------------------------
Node *findMin(Node *root)
{
    while (root && root->left)
        root = root->left;
    return root;
}

// ------------------------ FIND MAX ------------------------
Node *findMax(Node *root)
{
    while (root && root->right)
        root = root->right;
    return root;
}

// ------------------------ DELETE NODE ------------------------
Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else
    {
        // node with one or no child
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // node with two children
        Node *temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// ------------------------ TRAVERSALS ------------------------
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->key << " ";
}

// ------------------------ HEIGHT ------------------------
int height(Node *root)
{
    if (root == NULL)
        return -1;
    int hl = height(root->left);
    int hr = height(root->right);
    return max(hl, hr) + 1;
}

// ------------------------ COUNT NODES ------------------------
int countNodes(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// ------------------------ SUCCESSOR ------------------------
Node *successor(Node *root, int key)
{
    Node *curr = root;
    Node *succ = NULL;

    while (curr)
    {
        if (key < curr->key)
        {
            succ = curr;
            curr = curr->left;
        }
        else
            curr = curr->right;
    }
    return succ;
}

// ------------------------ PREDECESSOR ------------------------
Node *predecessor(Node *root, int key)
{
    Node *curr = root;
    Node *pred = NULL;

    while (curr)
    {
        if (key > curr->key)
        {
            pred = curr;
            curr = curr->right;
        }
        else
            curr = curr->left;
    }
    return pred;
}

// ------------------------ CLEAR TREE ------------------------
void clearTree(Node *root)
{
    if (root == NULL)
        return;
    clearTree(root->left);
    clearTree(root->right);
    delete root;
}

// ------------------------ MAIN DEMO ------------------------
int main()
{
    Node *root = NULL;

    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Min = " << findMin(root)->key << endl;
    cout << "Max = " << findMax(root)->key << endl;

    cout << "Deleting 20...\n";
    root = deleteNode(root, 20);

    cout << "Inorder after delete: ";
    inorder(root);
    cout << endl;

    cout << "Height = " << height(root) << endl;
    cout << "Nodes = " << countNodes(root) << endl;

    return 0;
}
