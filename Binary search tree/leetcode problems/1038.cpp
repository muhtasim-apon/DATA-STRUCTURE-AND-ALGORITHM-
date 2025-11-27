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
    // int j=0;
    // vector<int>num;
    // void inorder(TreeNode* root)
    // {
    //     if(root==NULL)return;
    //     inorder(root->left);
    //     num.push_back(root->val);
    //     inorder(root->right);
    // }
    // void prefix(vector<int>&num)
    // {
    // for(int i=1;i<num.size();i++)
    // {
    //     num[i]+=num[i-1];
    // }
    // }
    // void convert(TreeNode* root)
    // {
    //     if(root==NULL)return;
    //     convert(root->left);
    //     root->val=num[num.size()-1]-(j==0?0:num[j-1]);
    //     j++;
    //     convert(root->right);
    // }
    int sum = 0;
    TreeNode *bstToGst(TreeNode *root)
    {
        // TreeNode* current=root;
        //  inorder(root);
        //  prefix(num);
        //  convert(root);
        //  //current->val=num[num.size()-1];
        if (root == NULL)
            return NULL;
        root->right = bstToGst(root->right);
        sum += root->val;
        root->val = sum;
        root->left = bstToGst(root->left);
        return root;
    }
};