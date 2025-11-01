// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         stack<int>st;
//         queue<int>que;
//         while(head!=NULL)
//         {
//             st.push(head->val);
//             que.push(head->val);
//             head=head->next;
//         }
//         while(!st.empty())
//         {
//             if(st.top()!=que.front())return false;
//             st.pop();
//             que.pop();
//         }
//         return true;
//     }
// };