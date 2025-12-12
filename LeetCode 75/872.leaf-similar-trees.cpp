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
    vector<int> tree1;
    vector<int> tree2;
    void postorder1(TreeNode *root1)
    {
        if (root1 == NULL)
            return;
        postorder1(root1->left);
        postorder1(root1->right);
        if (root1->left == NULL && root1->right == NULL)
            tree1.push_back(root1->val);
    }
    void postorder2(TreeNode *root2)
    {
        if (root2 == NULL)
            return;
        postorder2(root2->left);
        postorder2(root2->right);
        if (root2->left == NULL && root2->right == NULL)
            tree2.push_back(root2->val);
    }
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        postorder1(root1);
        postorder2(root2);
        if (tree1 == tree2)
            return true;
        return false;
    }
};