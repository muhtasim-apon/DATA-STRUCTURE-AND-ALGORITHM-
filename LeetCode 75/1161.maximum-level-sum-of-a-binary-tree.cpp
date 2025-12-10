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
    vector<int> number;
    vector<int> ans;
    int m = INT_MIN;
    int final;
    int maxLevelSum(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        pq.push(root);
        number.push_back(root->val);
        ans.push_back(root->val);
        m = max(m, root->val);
        number.clear();
        while (!pq.empty())
        {
            int n = pq.size();
            for (int i = 1; i <= n; i++)
            {
                TreeNode *temp = pq.front();
                pq.pop();
                if (temp->left)
                {
                    pq.push(temp->left);
                    number.push_back(temp->left->val);
                }
                if (temp->right)
                {
                    pq.push(temp->right);
                    number.push_back(temp->right->val);
                }
            }
            if (number.size())
            {
                int sum = accumulate(number.begin(), number.end(), 0);
                ans.push_back(sum);
                m = max(m, sum);
            }
            number.clear();
        }
        for (int i = 0; i < ans.size(); i++)
        {
            if (ans[i] == m)
            {
                final = i + 1;
                break;
            }
        }
        return final;
    }
};