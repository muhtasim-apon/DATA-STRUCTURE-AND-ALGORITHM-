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
    int count = 0;
    queue<TreeNode *> lvl;
    map<TreeNode *, TreeNode *> parent;
    TreeNode *makeparent(TreeNode *root)
    {
        lvl.push(root);
        parent[root] = NULL;
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
    void countgood(TreeNode *root)
    {
        int a = root->val;
        bool test = true;
        while (root)
        {
            if (root->val > a)
            {
                test = false;
                break;
            }
            root = parent[root];
        }
        if (test)
            count++;
        return;
    }
    void traverse(TreeNode *root)
    {
        if (root == NULL)
            return;
        traverse(root->left);
        countgood(root);
        traverse(root->right);
    }
    int goodNodes(TreeNode *root)
    {
        makeparent(root);
        traverse(root);
        return count;
    }
};