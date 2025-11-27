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
    bool findTarget(TreeNode *root, int k)
    {
        inorder(root);
        for (int i = 0; i < number.size(); i++)
        {
            if (binary_search(number.begin() + i + 1, number.end(), k - number[i]))
                return true;
        }
        return false;
    }
};