//merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)return list2;
        if(list2==NULL)return list1;
        ListNode* dummy=new ListNode(0);
        ListNode* tail=dummy;
        while(list1 && list2)
        {
            if(list1->val<list2->val)
            {
                tail->next=list1;
                list1=list1->next;
                tail=tail->next;
            }
            else
            {
                tail->next=list2;
                list2=list2->next;
                tail=tail->next;
            }

        }
        while(list1)
        {
            tail->next=list1;
                list1=list1->next;
                tail=tail->next;
        }
        while(list2)
        {
            tail->next=list2;
                list2=list2->next;
                tail=tail->next;
        }
        ListNode* head=dummy;
        head=head->next;
       // free(dummy);
        return head;
    }
};