class Solution
{
public:
    int idx;                            // current root index in preorder
    unordered_map<int, int> inorderMap; // value -> index in inorder

    TreeNode *build(vector<int> &preorder, int l, int r)
    {
        if (l > r)
            return nullptr;

        int rootVal = preorder[idx++];
        TreeNode *root = new TreeNode(rootVal);

        int m = inorderMap[rootVal]; // find index in inorder
        root->left = build(preorder, l, m - 1);
        root->right = build(preorder, m + 1, r);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        idx = 0;
        inorderMap.clear();
        for (int i = 0; i < inorder.size(); i++)
            inorderMap[inorder[i]] = i;

        return build(preorder, 0, inorder.size() - 1);
    }
};