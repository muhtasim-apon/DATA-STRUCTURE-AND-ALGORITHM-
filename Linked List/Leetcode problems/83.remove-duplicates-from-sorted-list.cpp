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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL)
            return NULL;
        ListNode *current = head;
        while (current)
        {
            ListNode *temp = current;
            while (temp != NULL && temp->next != NULL && temp->val == temp->next->val)
                temp = temp->next;
            current->next = temp->next;
            current = temp->next;
        }
        return head;
    }
};