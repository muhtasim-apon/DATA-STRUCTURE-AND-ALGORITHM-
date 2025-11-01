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
class Solution {
public:
        vector<int>Traverse;
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL)return Traverse;
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        Traverse.push_back(root->val);
        return Traverse;
    }
};