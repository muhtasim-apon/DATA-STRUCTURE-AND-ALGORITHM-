//sort an linked list by using merge sort
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
class Solution {
public:
ListNode* middlepoint(ListNode* head)
{
    ListNode* slow=head;
    ListNode* fast=head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
ListNode* merge(ListNode* left, ListNode* right)
{
    if(left==NULL)return right;
    if(right==NULL)return left;
    ListNode *result=NULL;
    if(left->val<=right->val)
    {
        result=left;
        result->next=merge(left->next,right);
    }
    else
    {
        result=right;
        result->next=merge(left,right->next);
    }
    return result;
}
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode* middle=middlepoint(head);
        ListNode* righthalf=middle->next;
        middle->next=NULL;
        ListNode* left=sortList(head);
        ListNode* right=sortList(righthalf);
        return merge(left,right);
    }
};