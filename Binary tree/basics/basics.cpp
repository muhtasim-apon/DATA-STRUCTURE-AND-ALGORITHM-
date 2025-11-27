#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
    Node(int x) : key(x), left(NULL), right(NULL) {}
};

// -----------------------------------------------------
// INSERT (Level Order) — used for general binary tree
// -----------------------------------------------------
Node *insertNode(Node *root, int key)
{
    if (root == NULL)
    {
        return new Node(key);
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (!temp->left)
        {
            temp->left = new Node(key);
            break;
        }
        else
            q.push(temp->left);

        if (!temp->right)
        {
            temp->right = new Node(key);
            break;
        }
        else
            q.push(temp->right);
    }
    return root;
}

// -----------------------------------------------------
// SEARCH (DFS)
// -----------------------------------------------------
bool searchDFS(Node *root, int key)
{
    if (root == NULL)
        return false;
    if (root->key == key)
        return true;
    return searchDFS(root->left, key) || searchDFS(root->right, key);
}

// -----------------------------------------------------
// SEARCH (Level Order / BFS)
// -----------------------------------------------------
bool searchBFS(Node *root, int key)
{
    if (!root)
        return false;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp->key == key)
            return true;

        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    return false;
}

// -----------------------------------------------------
// FIND DEEPEST NODE
// -----------------------------------------------------
Node *deepestNode(Node *root)
{
    if (root == NULL)
        return NULL;

    queue<Node *> q;
    q.push(root);
    Node *temp;

    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    return temp; // last node visited
}

// -----------------------------------------------------
// DELETE NODE FROM BINARY TREE
// (replace target with deepest node)
// -----------------------------------------------------
Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
        return NULL;

    if (root->left == NULL && root->right == NULL)
    {
        if (root->key == key)
        {
            delete root;
            return NULL;
        }
        return root;
    }

    queue<Node *> q;
    q.push(root);

    Node *temp, *keyNode = NULL;

    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if (temp->key == key)
            keyNode = temp;

        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }

    if (keyNode != NULL)
    {
        Node *deep = deepestNode(root);
        keyNode->key = deep->key; // replace

        // delete deepest node
        queue<Node *> q2;
        q2.push(root);

        while (!q2.empty())
        {
            temp = q2.front();
            q2.pop();

            if (temp->left)
            {
                if (temp->left == deep)
                {
                    temp->left = NULL;
                    delete deep;
                    return root;
                }
                q2.push(temp->left);
            }

            if (temp->right)
            {
                if (temp->right == deep)
                {
                    temp->right = NULL;
                    delete deep;
                    return root;
                }
                q2.push(temp->right);
            }
        }
    }
    return root;
}

// -----------------------------------------------------
// TRAVERSALS
// -----------------------------------------------------
void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

void preorder(Node *root)
{
    if (!root)
        return;
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->key << " ";
}

// -----------------------------------------------------
// LEVEL ORDER TRAVERSAL
// -----------------------------------------------------
void levelOrder(Node *root)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        cout << curr->key << " ";

        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
}

// -----------------------------------------------------
// HEIGHT OF TREE
// -----------------------------------------------------
int height(Node *root)
{
    if (!root)
        return -1;
    return 1 + max(height(root->left), height(root->right));
}

// -----------------------------------------------------
// COUNT NODES
// -----------------------------------------------------
int countNodes(Node *root)
{
    if (!root)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// -----------------------------------------------------
// FIND PARENT OF A NODE
// -----------------------------------------------------
Node *findParent(Node *root, int key)
{
    if (!root)
        return NULL;
    if (root->left && root->left->key == key)
        return root;
    if (root->right && root->right->key == key)
        return root;

    Node *left = findParent(root->left, key);
    if (left)
        return left;

    return findParent(root->right, key);
}

// -----------------------------------------------------
// MIRROR TREE
// -----------------------------------------------------
void mirror(Node *root)
{
    if (!root)
        return;
    swap(root->left, root->right);
    mirror(root->left);
    mirror(root->right);
}

// -----------------------------------------------------
// CLEAR TREE
// -----------------------------------------------------
void clear(Node *root)
{
    if (!root)
        return;
    clear(root->left);
    clear(root->right);
    delete root;
}

// -----------------------------------------------------
// MAIN (DEMO)
// -----------------------------------------------------
int main()
{
    Node *root = NULL;

    root = insertNode(root, 10);
    insertNode(root, 20);
    insertNode(root, 30);
    insertNode(root, 40);
    insertNode(root, 50);

    cout << "Level Order: ";
    levelOrder(root);
    cout << endl;

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Height = " << height(root) << endl;
    cout << "Nodes = " << countNodes(root) << endl;

    cout << "Deleting 30...\n";
    root = deleteNode(root, 30);

    cout << "Level Order After Delete: ";
    levelOrder(root);
    cout << endl;

    return 0;
}
