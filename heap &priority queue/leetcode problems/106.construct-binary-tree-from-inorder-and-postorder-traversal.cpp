/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int idx;
    int find(vector<int> &inorder, vector<int> &postoder, int x)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            if (inorder[i] == x)
                return i;
        }
        return -1;
    }
    TreeNode *build(vector<int> &inorder, vector<int> &postorder, int l, int r)
    {
        if (l > r)
            return NULL;
        TreeNode *root = new TreeNode(postorder[idx--]);
        int m = find(inorder, postorder, root->val);
        root->right = build(inorder, postorder, m + 1, r);
        root->left = build(inorder, postorder, l, m - 1);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        idx = postorder.size() - 1;
        return build(inorder, postorder, 0, idx);
    }
};