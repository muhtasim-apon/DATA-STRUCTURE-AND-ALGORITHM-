#include<bits/stdc++.h>
#define ll long long
using namespace std;
void muhtasim()
{
    ll n,m;
    cin>>n>>m;
    queue<pair<ll,ll>>line;
    stack<ll>index;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        line.push({x,i+1});
    }
    while(!line.empty())
    {
        if(line.front().first>m)
        {
            line.front().first-=m;
            line.push(line.front());
            line.pop();
        }
        else
        {
            index.push(line.front().second);
            line.pop();
        }
    }
    cout<<index.top()<<"\n";

}
int main()
{
ios::sync_with_stdio(false);
cin.tie(nullptr);
ll tests=1;
while(tests--)
{
muhtasim();
}
}