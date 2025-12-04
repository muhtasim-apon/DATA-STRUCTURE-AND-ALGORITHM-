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
    vector<int> numbers;
    vector<vector<int>> ans;

    void bst(TreeNode *root)
    {
        int i = 0;
        if (root == NULL)
            return;
        pq.push(root);
        numbers.push_back(root->val);
        ans.push_back(numbers);
        numbers.clear();
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
                    numbers.push_back(temp->left->val);
                }
                if (temp->right)
                {
                    pq.push(temp->right);
                    numbers.push_back(temp->right->val);
                }
            }
            if (numbers.size() != 0)
            {
                ans.push_back(numbers);
                numbers.clear();
            }
        }
    }
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        bst(root);
        return ans;
    }
};