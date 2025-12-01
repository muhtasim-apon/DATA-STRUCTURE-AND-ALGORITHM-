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
    vector<int> ans;
    int height(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int h1 = height(root->left);
        int h2 = height(root->right);
        // h2=height1(root->right);
        return 1 + max(h1, h2);
    }
    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        int h1 = height(root->left);
        int h2 = height(root->right);
        ans.push_back(h1 + h2);
        inorder(root->right);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        ans.clear();
        inorder(root);
        ans.push_back(0);
        sort(ans.begin(), ans.end());
        // for(auto x:ans)cout<<x<<" ";
        return ans.back();
    }
};