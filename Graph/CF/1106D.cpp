#include<bits/stdc++.h>
#define ll long long
using namespace std;

// void dfs(ll u,vector<bool> &visited, vector<vector<ll>> &adj, vector<ll> &ans)
// {
//     visited[u]=true;
//     ans.push_back(u);
//     ll next=1e9;
//     priority_queue<ll,vector<ll>,greater<ll>>pq;
//     for(auto v: adj[u])
//     {
//         if(!visited[v])
//         {
//             pq.push(v);
//         }
//     }
//     while(!pq.empty())
//     {
//         ll v=pq.top();
//         pq.pop();
//         if(!visited[v])
//         {
//             dfs(v,visited,adj,ans);
//         }   
//     }
//     pq.clear();
// }
void muhtasim()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>adj(n);
    for(int i=1;i<=m;i++)
    {
        ll u,v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    vector<bool>visited(n,false);
    vector<ll>ans;
    //dfs(0,visited,adj,ans);
    // for(int i=0;i<n;i++)
    // {
    //     if(!visited[i])
    //     {
    //         dfs(i,visited,adj,ans);
    //     }
    // }
    priority_queue<ll,vector<ll>,greater<ll>>pq;
    pq.push(0);
    while(!pq.empty())
    {
        ll u=pq.top();
        pq.pop();
        if(visited[u])continue;
        visited[u]=true;
        ans.push_back(u);
        for(auto v: adj[u])
        {
            if(!visited[v])pq.push(v);
        }
    }
    //ans.pop_back();
    for(auto x: ans)
    {
        cout<<x+1<<" ";
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