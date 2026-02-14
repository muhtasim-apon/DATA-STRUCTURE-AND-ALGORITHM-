/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (!head || !head->next)
            return NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        bool test = false;
        while (slow != NULL && fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                test = true;
                break;
            }
        }
        if (!test)
            return NULL;
        // else return slow;
        slow = head;
        // fast=head;
        while (slow != fast)
        {

            slow = slow->next;
            fast = fast->next;
            if (slow == fast)
                break;
        }
        ListNode *ans = head;
        int count = 0;
        // while(ans!=slow)
        // {
        //     ans=ans->next;
        //     count++;
        // }
        return slow;
    }
};