#include <bits/stdc++.h>
using namespace std;

// Huffman Tree Node
struct Node
{
    int freq;
    Node *left, *right;

    Node(int f)
    {
        freq = f;
        left = right = NULL;
    }
};

// Min Heap comparator
struct Compare
{
    bool operator()(Node *a, Node *b)
    {
        return a->freq > b->freq; // min heap
    }
};

// Preorder traversal to generate codes
void generateCodes(Node *root, string code, vector<string> &ans)
{
    if (!root)
        return;

    // Leaf node
    if (!root->left && !root->right)
    {
        ans.push_back(code);
        return;
    }

    generateCodes(root->left, code + "0", ans);
    generateCodes(root->right, code + "1", ans);
}

// Huffman Coding function
vector<string> huffmanCodes(string s, vector<int> freq)
{
    priority_queue<Node *, vector<Node *>, Compare> pq;

    // Step 1: push all frequencies
    for (int f : freq)
        pq.push(new Node(f));

    // Step 2: build Huffman Tree
    while (pq.size() > 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();

        Node *newNode = new Node(left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    // Step 3: generate codes
    vector<string> ans;
    generateCodes(pq.top(), "", ans);

    return ans;
}

// -------- MAIN --------
int main()
{
    string s = "abcdef";
    vector<int> freq = {5, 9, 12, 13, 16, 45};

    vector<string> codes = huffmanCodes(s, freq);

    cout << "Huffman Codes:\n";
    for (string c : codes)
        cout << c << " ";

    return 0;
}
