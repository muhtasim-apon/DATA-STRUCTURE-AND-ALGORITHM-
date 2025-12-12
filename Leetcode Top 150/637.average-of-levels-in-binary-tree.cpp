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
    vector<long long> number;
    vector<double> ans;
    int final;
    vector<double> averageOfLevels(TreeNode *root)
    {
        ans.clear();
        pq.push(root);
        number.push_back(root->val);
        double a = round(root->val * 1e5) / 1e5;
        ans.push_back(a);
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
                long long sum = accumulate(number.begin(), number.end(), 0LL);
                double avg = sum / (double)number.size();
                double deci = round(avg * 1e5) / 1e5;
                ans.push_back(deci);
            }
            number.clear();
        }
        return ans;
    }
};