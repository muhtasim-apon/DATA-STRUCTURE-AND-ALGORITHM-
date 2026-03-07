#include<bits/stdc++.h>
#define ll long long
using namespace std;
void dfs(ll &a, ll &b, vector<ll> & v, ll &count, bool &test)
{
    if(a==b)
    {
        test=true;
        //count++;
        //v.push_back(a);
        return;
    }
    if(a>b)return;
    if(b%2==0)
    {
        b/=2;
        count++;
        v.push_back(b);
        dfs(a,b,v,count,test);
    }
    else if(b%10==1)
    {
        b=(b-1)/10;
        count++;
        v.push_back(b);
        dfs(a,b,v,count,test);
    }
}
void muhtasim()
{
    ll a,b;
    ll count=0;
    bool test=false;
    cin>>a>>b;
    ll c=b;
    vector<ll> v;
    dfs(a,b,v,count,test);
    if(test)
    {
        cout<<"YES\n";
        cout<<(count+1)<<"\n";
        //v.push_back(c);
        reverse(v.begin(),v.end());
        for(auto i:v)
        {
            cout<<i<<" ";
        }
        cout<<c<<"\n";
    }
    else
    {
        cout<<"NO\n";
    }
}
int main()
{
ios::sync_with_stdio(false);
cin.tie(nullptr);
ll tests=1;
//cin>>tests;
while(tests--)
{
muhtasim();
}
}