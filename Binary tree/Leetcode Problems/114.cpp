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
    vector<int> number;
    void preorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        number.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
    void flatten(TreeNode *root)
    {
        preorder(root);
        if (number.size() == 0)
            return;
        TreeNode *current = root;
        for (int i = 1; i < number.size(); i++)
        {
            current->left = NULL;
            current->right = new TreeNode(number[i]);
            current = current->right;
        }
    }
};