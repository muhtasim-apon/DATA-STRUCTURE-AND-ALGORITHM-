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
    int total;
    int ans = 0;
    map<TreeNode *, TreeNode *> parent;
    // set<TreeNode*>path1;
    queue<TreeNode *> lvl;
    TreeNode *makeparent(TreeNode *root)
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
        return root;
    }

    void checksum(TreeNode *root, int total)
    {
        long long sum = 0;
        while (root)
        {
            sum = sum + root->val;
            if (sum == total)
            {
                ans++;
            }
            // else if(sum>total)return;
            root = parent[root];
        }
    }

    void traverse(TreeNode *root)
    {
        if (root == NULL)
            return;
        traverse(root->left);
        checksum(root, total);
        traverse(root->right);
    }

    int pathSum(TreeNode *root, int targetSum)
    {
        total = targetSum;
        if (root == NULL)
            return 0;
        makeparent(root);
        traverse(root);
        return ans;
    }
};