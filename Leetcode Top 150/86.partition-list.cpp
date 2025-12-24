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
    ListNode *partition(ListNode *head, int x)
    {
        if (head == NULL)
            return NULL;
        vector<int> numbers;
        ListNode *current = head;
        ListNode *current1 = head;
        ListNode *current2 = head;
        while (current)
        {
            if (current->val < x)
                numbers.push_back(current->val);
            // current->val=-300;
            current = current->next;
        }
        while (current1)
        {
            if (current1->val >= x)
                numbers.push_back(current1->val);
            current1 = current1->next;
        }
        // for(auto x:numbers)cout<<x<<" ";
        for (auto x : numbers)
        {
            current2->val = x;
            current2 = current2->next;
        }
        return head;
    }
};