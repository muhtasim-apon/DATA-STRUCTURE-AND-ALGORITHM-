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
    map<TreeNode *, TreeNode *> parent;
    vector<int> numbers;
    queue<TreeNode *> lvl;
    void makeparents(TreeNode *root)
    {
        parent[root] = NULL;
        lvl.push(root);
        while (!lvl.empty())
        {
            TreeNode *current = lvl.front();
            lvl.pop();
            if (current->left)
            {
                lvl.push(current->left);
                parent[current->left] = current;
            }
            if (current->right)
            {
                lvl.push(current->right);
                parent[current->right] = current;
            }
        }
    }
    void calculate(TreeNode *root)
    {
        string s;
        // root=parent[root];
        while (root)
        {
            string s1 = to_string(root->val);
            s = s + s1;
            root = parent[root];
        }
        reverse(s.begin(), s.end());
        int sum1 = stoi(s);
        numbers.push_back(sum1);
        return;
    }
    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        if (root->left == NULL && root->right == NULL)
            calculate(root);
        inorder(root->right);
    }
    int sumNumbers(TreeNode *root)
    {
        makeparents(root);
        inorder(root);
        long long ans = accumulate(numbers.begin(), numbers.end(), 0LL);
        // for(auto x: numbers) cout<<x<<" ";
        return ans;
    }
};