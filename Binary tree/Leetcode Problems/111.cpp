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
    int minDepth(TreeNode* root) {
         if(root==NULL)return 0;
       queue<TreeNode*>q;
        int depth=0;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            depth++;
            for(int i=0;i<size;i++)
            {
                TreeNode* c=q.front();
                q.pop();
                if(c->left==NULL && c->right==NULL)  return depth;
                if(c->left)q.push(c->left);
                if(c->right)q.push(c->right);
            }
        }
       return depth;
    }
};