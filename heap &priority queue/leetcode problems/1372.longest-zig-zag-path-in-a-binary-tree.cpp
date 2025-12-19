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
    int ans = 0;
    int longestZigZag(TreeNode *root)
    {
        queue<pair<TreeNode *, pair<int, int>>> pq;
        if (!root)
            return 0;
        pq.push({root, {-1, 0}});

        while (!pq.empty())
        {
            TreeNode *current = pq.front().first;
            int dir = pq.front().second.first;
            int len = pq.front().second.second;
            ans = max(ans, len);
            pq.pop();
            if (current->left)
            {
                if (dir != 0)
                    pq.push({current->left, {0, len + 1}});
                else
                    pq.push({current->left, {0, 1}});
            }
            if (current->right)
            {
                if (dir != 1)
                    pq.push({current->right, {1, len + 1}});
                else
                    pq.push({current->right, {1, 1}});
            }
        }
        return ans;
    }
};