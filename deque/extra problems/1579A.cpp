#include<bits/stdc++.h>
#define ll long long
using namespace std;
void muhtasim()
{
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    deque<ll>lexico;
    lexico.push_back(v[0]);
    for(int i=1;i<n;i++)
    {
        if(lexico.front()>v[i])lexico.push_front(v[i]);
        else lexico.push_back(v[i]);
    }
    for(int i=0;i<lexico.size();i++)cout<<lexico[i]<<" ";
    cout<<"\n";
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