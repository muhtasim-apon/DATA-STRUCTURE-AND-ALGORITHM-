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
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *current = head;
        ListNode *current1 = head;
        vector<int> nums;
        while (current)
        {
            nums.push_back(current->val);
            current = current->next;
        }
        reverse(nums.begin() + left - 1, nums.begin() + right);
        for (auto x : nums)
        {
            current1->val = x;
            current1 = current1->next;
        }
        return head;
    }
};