#include<bits/stdc++.h>
#define ll long long
using namespace std;
void dfs(ll node,map<ll,vector<ll>>&adj,set<ll>&visited,vector<ll>&ans)
{
    visited.insert(node);
    ans.push_back(node);
    for(auto v:adj[node])
    {
        if(visited.find(v)==visited.end())
        {
            dfs(v,adj,visited,ans);
        }
    }
}
void muhtasim()
{
    ll n;
    cin>>n;
    map<ll,vector<ll>>adj;
    //map<ll,bool>visited;
    set<ll>visited;
    //int k=0;
    for(int i=0;i<n;i++)
    {
        ll u,v;
        cin>>u>>v;
        // s.insert(u);
        // s.insert(v);
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    int start=0;
    for(auto x: adj)
    {
        //int start=0;
        if(x.second.size()==1)
        {
            start=x.first;
            break;
        }
    }
    vector<ll>ans;
    dfs(start,adj,visited,ans);
    for(auto v:ans)
    {
        cout<<v+1<<" ";
    }
     cout<<"\n";

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