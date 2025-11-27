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
    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        number.push_back(root->val);
        inorder(root->right);
    }
    TreeNode *increasingBST(TreeNode *root)
    {
        inorder(root);
        if (number.size() == 0)
            return NULL;
        TreeNode *root1 = new TreeNode(number[0]);
        TreeNode *current = root1;
        for (int i = 1; i < number.size(); i++)
        {
            current->right = new TreeNode(number[i]);
            current = current->right;
        }
        return root1;
    }
};