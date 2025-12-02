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
    int sum3 = 0;
    int accume(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int sum = 0;
        sum += accume(root->left);
        sum += root->val;
        sum += accume(root->right);
        return sum;
    }
    int total(TreeNode *root)
    {

        if (root == NULL)
            return 0;
        total(root->left);
        // sum1=0,sum2=0;
        sum3 += abs(accume(root->left) - accume(root->right));
        total(root->right);
        return sum3;
    }
    int findTilt(TreeNode *root)
    {
        total(root);
        return sum3;
    }
};