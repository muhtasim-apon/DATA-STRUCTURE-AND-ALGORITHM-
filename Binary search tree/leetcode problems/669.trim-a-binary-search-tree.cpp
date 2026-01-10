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
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        while (root && (root->val < low || root->val > high))
        {
            if (root->val > high)
                root = root->left;
            else
                root = root->right;
        }
        if (!root)
            return NULL;
        TreeNode *current = root;
        while (current)
        {
            while (current->left && current->left->val < low)
            {
                current->left = current->left->right;
            }
            current = current->left;
        }
        current = root;
        while (current)
        {
            while (current->right && current->right->val > high)
            {
                current->right = current->right->left;
            }
            current = current->right;
        }
        return root;
    }
};