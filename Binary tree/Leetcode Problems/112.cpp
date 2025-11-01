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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)return false;
        else
        {
            queue<pair<TreeNode*,int>>q;
            pair<TreeNode*,int>p;
            q.push({root,root->val});
            while(!q.empty())
            {
                p=q.front();
                TreeNode* c=p.first;
                int currentsum=p.second;
                q.pop();
                if(!c->left && !c->right)
                {
                    if(currentsum==targetSum)return true;
                }
               if(c->left) q.push({c->left,currentsum+c->left->val});
               if(c->right) q.push({c->right,currentsum+c->right->val});

        }
            return false;
        }
    }
};