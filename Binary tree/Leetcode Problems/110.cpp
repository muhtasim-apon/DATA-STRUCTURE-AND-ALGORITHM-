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
    // int h1=0,h2=0;
    bool test = true;
    int height(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int h1 = height(root->left);
        int h2 = height(root->right);
        // h2=height1(root->right);
        return 1 + max(h1, h2);
    }
    //     int height2(TreeNode* root)
    // {
    //     if(root==NULL)return 0;
    //     //h1=height2(root->left);
    //     int h2=height2(root->right);
    //     return 1+h2;
    // }
    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        int h1 = height(root->left);
        int h2 = height(root->right);
        int ans = abs(h2 - h1);
        if (ans > 1)
        {
            test = false;
            return;
        }
        inorder(root->right);
    }
    bool isBalanced(TreeNode *root)
    {
        inorder(root);
        if (test)
            return true;
        return false;
    }
};