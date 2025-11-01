#include<bits/stdc++.h>
#define ll long long
using namespace std;
void muhtasim()
{
  ll n;
  cin>>n;
  string s;
  cin>>s;
  ll count=0,size=-1;
  stack<char>st;
  stack<int>freq;
  for(int i=0;i<s.size();i++)
  {
    if(st.empty() && s[i]=='_')
    {
        st.push(s[i]);
        freq.push(i);

    }
    else if(s[i]=='(')
    {
        st.push(s[i]);
        freq.push(i);
    }
   else if(s[i]==')' || s[i]=='_')
    {
        if(st.top()=='(' || st.top()=='_')
        {
            count+=i-freq.top();
            st.pop();
            freq.pop();
        }
    }
    //cout<<count<<"\n";
}
cout<<count<<"\n";

}
int main()
{
ios::sync_with_stdio(false);
cin.tie(nullptr);
ll tests;
cin>>tests;
while(tests--)
{
muhtasim();
}
}