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
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == NULL)
            return NULL;
        vector<int> number;
        ListNode *current1 = head;
        ListNode *current2 = head;
        ListNode *ans = head;
        int size1 = 0, size2 = 0;
        while (current1)
        {
            size1++;
            if (size1 % 2 != 0)
            {
                number.push_back(current1->val);
            }
            current1 = current1->next;
        }
        while (current2)
        {
            size2++;
            if (size2 % 2 == 0)
            {
                number.push_back(current2->val);
            }
            current2 = current2->next;
        }
        for (auto x : number)
            cout << x << " ";
        cout << "\n";
        ans = new ListNode(number[0]);
        ListNode *temp = ans;
        for (int i = 1; i < number.size(); i++)
        {
            ans->next = new ListNode(number[i]);
            ans = ans->next;
        }
        return temp;
    }
};