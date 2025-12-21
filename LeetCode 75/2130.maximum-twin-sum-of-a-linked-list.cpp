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
    int pairSum(ListNode *head)
    {
        int sum = 0;
        ListNode *current = head;
        vector<int> numbers;
        while (current)
        {
            numbers.push_back(current->val);
            current = current->next;
        }
        int n = numbers.size();
        for (int i = 0; i < n; i++)
        {
            if (i == n - i - 1)
                break;
            sum = max(sum, numbers[i] + numbers[n - i - 1]);
        }
        return sum;
    }
};