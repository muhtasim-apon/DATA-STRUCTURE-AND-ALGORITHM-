class Solution
{
public:
    TreeNode *constructBST(vector<int> &preorder, int low, int high)
    {
        if (low > high)
            return NULL;
        int m = low + 1;
        // if(preorder.size()%2==0)mid++;
        TreeNode *root = new TreeNode(preorder[low]);
        while (m <= high && preorder[m] < preorder[low])
            m++;
        root->left = constructBST(preorder, low + 1, m - 1);
        root->right = constructBST(preorder, m, high);
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        return constructBST(preorder, 0, preorder.size() - 1);
    }
};