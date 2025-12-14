/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    map<TreeNode *, TreeNode *> parent;
    set<TreeNode *> path1;
    queue<TreeNode *> lvl;
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        parent[root] = NULL;
        lvl.push(root);
        while (!(parent.count(p) && parent.count(q)))
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
        while (p)
        {
            path1.insert(p);
            p = parent[p];
        }
        while (q)
        {
            if (path1.count(q))
                return q;
            q = parent[q];
        }
        return root;
    }
};