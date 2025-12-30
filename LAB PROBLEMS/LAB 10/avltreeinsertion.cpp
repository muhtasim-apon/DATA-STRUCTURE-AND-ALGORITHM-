#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int key;
    TreeNode *left;
    TreeNode *right;
    int height;
};

int height(TreeNode *node)
{
    return node ? node->height : 0;
}

TreeNode *create(int key)
{
    TreeNode *node = new TreeNode();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return node;
}

int balanceFactor(TreeNode *node)
{
    return node ? height(node->left) - height(node->right) : 0;
}

TreeNode *rightRotate(TreeNode *y)
{
    TreeNode *x = y->left;
    TreeNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

TreeNode *LeftRotation(TreeNode *x)
{
    TreeNode *y = x->right;
    TreeNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

TreeNode *insert(TreeNode *node, int key)
{
    if (!node)
        return create(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = balanceFactor(node);

    if (balance > 1 && key < node->left->key)
    {
        cout << "Rotation Used: LL (Right Rotation)\n";
        return rightRotate(node);
    }

    if (balance < -1 && key > node->right->key)
    {
        cout << "Rotation Used: RR (Left Rotation)\n";
        return LeftRotation(node);
    }

    if (balance > 1 && key > node->left->key)
    {
        cout << "Rotation Used: LR (Left Rotation + Right Rotation)\n";
        node->left = LeftRotation(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        cout << "Rotation Used: RL (Right Rotation + Left Rotation)\n";
        node->right = rightRotate(node->right);
        return LeftRotation(node);
    }

    return node;
}

void inorder(TreeNode *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

bool searchkey(TreeNode *root, int key)
{
    if (!root)
        return false;
    if (root->key == key)
        return true;
    if (key < root->key)
        return searchkey(root->left, key);
    return searchkey(root->right, key);
}

int main()
{
    TreeNode *root = nullptr;
    int choice, value;

    do
    {
        cout << "\n--- AVL Tree Insertion Menu ---\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Display Inorder Traversal\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            root = insert(root, value);
            cout << "Inserted successfully.\n";
            break;

        case 2:
            cout << "Enter value to searchkey: ";
            cin >> value;
            cout << (searchkey(root, value) ? "Value found.\n" : "Value not found.\n");
            break;

        case 3:
            cout << "Inorder Traversal: ";
            if (root)
                inorder(root);
            else
                cout << "Tree is empty.";
            cout << endl;
            break;

        case 4:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
