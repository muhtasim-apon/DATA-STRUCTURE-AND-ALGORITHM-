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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == NULL)
            return NULL;
        int size = 0;
        ListNode *current = head;
        while (current)
        {
            size++;
            current = current->next;
        }
        cout << size << "\n";
        int pos = size - n;
        ListNode *current1 = head;
        if (size == n)
            return current1->next;
        for (int i = 0; i < pos - 1; i++)
        {
            current1 = current1->next;
        }
        if (current1->next->next != NULL)
            current1->next = current1->next->next;
        else
            current1->next = NULL;
        return head;
    }
};