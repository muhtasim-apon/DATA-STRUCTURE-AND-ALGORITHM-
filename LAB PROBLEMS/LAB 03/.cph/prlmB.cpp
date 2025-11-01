#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    stack<char>st;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            st.push(s[i]);
        }
        if((s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/') && !st.empty())
        {
            int a=st.top()-'0';
            st.pop();
            int b=st.top()-'0';
            st.pop();
            int c;
            if(s[i]=='+')c=a+b;
            else if(s[i]=='-')c=b-a;
            else if(s[i]=='*')c=b*a;
            else
            {
                if(a==0)
                {
                    c=b/2;
                }
                else c=b/a;
            }
            st.push(c+'0');
        }
        else if(s[i]=='#' && !st.empty())
        {
            int temp=st.top()-'0';
            st.pop();
            temp++;
            st.push(temp+'0');
        }
        else if(s[i]=='$' && !st.empty())
        {
            int temp=st.top()-'0';
            st.pop();
            temp--;
            st.push(temp+'0');
        }
    }
    cout<<st.top()-'0'<<"\n";
    return 0;
}