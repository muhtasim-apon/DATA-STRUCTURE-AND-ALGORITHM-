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
    vector<int> nums;
    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        nums.push_back(root->val);
        inorder(root->right);
    }
    TreeNode *buildBST(vector<int> &nums, int low, int high)
    {

        TreeNode *root = NULL;
        if (low > high)
            return NULL;

        int mid = low + (high - low) / 2;
        root = new TreeNode(nums[mid]);
        root->left = buildBST(nums, low, mid - 1);
        root->right = buildBST(nums, mid + 1, high);
        return root;
    }
    TreeNode *balanceBST(TreeNode *root)
    {
        inorder(root);
        return buildBST(nums, 0, nums.size() - 1);
    }
};