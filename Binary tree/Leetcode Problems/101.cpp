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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;
        queue<TreeNode*>q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty())
        {
            TreeNode* c=q.front();
            q.pop();
            TreeNode* d=q.front();
            q.pop();
            if(c==NULL && d==NULL)continue;
           else  if((c==NULL && d!=NULL) || (c!=NULL && d==NULL))return false;
           else if(c->val!=d->val)return false;
            q.push(c->left);
            q.push(d->right);
            q.push(c->right);
            q.push(d->left);
        }
        return true;
    }
};