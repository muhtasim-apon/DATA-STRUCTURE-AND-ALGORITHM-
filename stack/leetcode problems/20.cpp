class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                st.push(s[i]);
            }
            else if(st.empty() && (s[i]==')'|| s[i]==']' || s[i]=='}'))
            {
                return false;
            }
            else if((s[i]==')'&& st.top()=='(') || (s[i]=='}'&& st.top()=='{')|| (s[i]==']'&& st.top()=='['))
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        if(st.empty())return true;
        return false;
    }
};
#include <stack>
#include <string>
using namespace std;
#include <iostream>
int main()
{
    Solution s;
    string str="()";
    cout<<s.isValid(str);
}