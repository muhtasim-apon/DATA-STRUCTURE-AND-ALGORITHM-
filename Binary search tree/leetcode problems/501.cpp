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
    map<int, int> freq;
    int n1 = 1e9;
    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        freq[root->val]++;
        n1 = min(n1, root->val);
        inorder(root->right);
    }
    vector<int> findMode(TreeNode *root)
    {
        vector<int> ans;
        inorder(root);
        int m = -1e9;
        for (auto x : freq)
        {
            m = max(m, x.second);
        }
        for (auto x : freq)
        {
            if (x.second == m)
                ans.push_back(x.first);
        }
        return ans;
    }
};