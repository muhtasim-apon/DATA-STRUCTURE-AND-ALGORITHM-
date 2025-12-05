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
    queue<TreeNode *> pq;
    bool isCompleteTree(TreeNode *root)
    {
        if (!root)
            return true;
        pq.push(root);
        bool test = false;
        while (!pq.empty())
        {
            TreeNode *current = pq.front();
            pq.pop();
            if (!current)
                test = true;
            else
            {
                if (test)
                    return false;
                pq.push(current->left);
                pq.push(current->right);
            }
        }
        return true;
    }
};