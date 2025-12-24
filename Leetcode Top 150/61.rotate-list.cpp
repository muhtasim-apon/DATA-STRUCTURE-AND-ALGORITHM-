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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL)
            return NULL;
        if (head->next == NULL || k == 0)
            return head;
        ListNode *current1 = head;
        ListNode *current2 = head;
        ListNode *prev = head;
        int size = 0;
        while (current1)
        {
            size++;
            current1 = current1->next;
        }
        int reduce = k % size;
        if (reduce == 0)
            return head;
        int rot = size - reduce;
        for (int i = 0; i < rot; i++)
        {
            prev = current2;
            current2 = current2->next;
        }
        prev->next = NULL;
        ListNode *head1 = current2;
        ListNode *temp = head1;
        while (temp->next)
            temp = temp->next;
        temp->next = head;
        return head1;
    }
};