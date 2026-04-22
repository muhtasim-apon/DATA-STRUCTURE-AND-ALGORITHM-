#include<bits/stdc++.h>
#define ll long long
using namespace std;
void dfs1(ll u,vector<vector<ll>>&adj1,vector<bool>&visited1,ll &count1,ll &maxpath1, ll &target)
{
    visited1[u]=true;
    count1++;
     if(count1>maxpath1)
     {
         maxpath1=count1;
         target=u;
     }
    for(auto v: adj1[u])
    {
        if(!visited1[v])
        {
            dfs1(v,adj1,visited1,count1,maxpath1,target);
        }
    }
    count1--;
}

void dfs2(ll src,ll &target,vector<vector<ll>>&adj2,vector<bool>&visited2,ll &count2,ll &maxpath2)
{
    visited2[src]=true;
    count2++;
     if(count2>maxpath2)
     {
         maxpath2=count2;
     }
    for(auto v: adj2[src])
    {
        if(!visited2[v])
        {
            dfs2(v,target,adj2,visited2,count2,maxpath2);
        }
    }
   if(src!=target) count2--;
   else maxpath2=count2;
}
void muhtasim()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>adj1(n);
    vector<vector<ll>>adj2(n);
    for(ll i=1;i<=n-1;i++)
    {
        ll u,v;
        cin>>u>>v;
        adj1[u-1].push_back(v-1);
        adj2[u-1].push_back(v-1);
    }
    vector<bool>visited1(n,false);
    vector<bool>visited2(n,false);
    ll count1=0,maxpath1=0;
    ll count2=0,maxpath2=0;
    ll target=0,src=0;
    dfs1(m-1,adj1,visited1,count1,maxpath1,target);
    maxpath1--;
    dfs2(src,target,adj2,visited2,count2,maxpath2);
    maxpath2--;
     cout<<"maxpath1: "<<maxpath1<<"\n";
     cout<<"maxpath2: "<<maxpath2<<"\n";
    ll ans=2*max(maxpath1,maxpath2);
    cout<<ans<<"\n";

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