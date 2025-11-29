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
    vector<int> real;
    vector<int> imposter;
    TreeNode *current0 = NULL;
    TreeNode *current1 = NULL;
    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        number.push_back(root->val);
        inorder(root->right);
    }
    void get(vector<int> &number)
    {
        real = number;
        sort(real.begin(), real.end());
        for (int i = 0; i < number.size(); i++)
        {
            if (number[i] != real[i])
            {
                imposter.push_back(number[i]);
            }
        }
    }
    void recover1(TreeNode *root)
    {
        bool test1 = true;
        if (root == NULL)
            return;
        recover1(root->left);
        if (root->val == imposter[0] && test1)
        {
            current0 = root;
            test1 = false;
        }
        if (root->val == imposter[1])
        {
            current1 = root;
        }
        recover1(root->right);
    }
    void recover2(TreeNode *root)
    {
        if (root == NULL)
            return;
        if (current0)
            current0->val = imposter[1];
        if (current1)
            current1->val = imposter[0];
    }
    void recoverTree(TreeNode *root)
    {
        inorder(root);
        get(number);
        recover1(root);
        recover2(root);
    }
};