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
    set<int> ans;
    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        if (root->left != NULL && root->right != NULL)
            root->val = min(root->left->val, root->right->val);
        inorder(root->right);
    }
    void inorder1(TreeNode *root)
    {
        if (root == NULL)
            return;
        inorder1(root->left);
        ans.insert(root->val);
        inorder1(root->right);
    }
    int findSecondMinimumValue(TreeNode *root)
    {
        ans.clear();
        inorder(root);
        inorder1(root);
        if (ans.size() == 0 || ans.size() == 1)
            return -1;
        //  sort(ans.begin(),ans.end());
        auto it = ans.begin();
        it++;
        return *it;
    }
};