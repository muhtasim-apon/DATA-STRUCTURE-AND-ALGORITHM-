/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    vector<int> number;
    void list(ListNode *head)
    {
        while (head != NULL)
        {
            number.push_back(head->val);
            head = head->next;
        }
    }
    TreeNode *construct(vector<int> &number, int low, int high)
    {
        if (low > high)
            return NULL;
        int mid = low + (high - low) / 2;
        TreeNode *root = new TreeNode(number[mid]);
        root->left = construct(number, low, mid - 1);
        root->right = construct(number, mid + 1, high);
        return root;
    }
    TreeNode *sortedListToBST(ListNode *head)
    {
        list(head);
        return construct(number, 0, number.size() - 1);
    }
};