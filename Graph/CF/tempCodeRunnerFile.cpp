#include<bits/stdc++.h>
#define ll long long
using namespace std;
void toposort(ll node,vector<vector<ll>>&adj,vector<bool>&visited,stack<ll>&st)
{
    visited[node]=true;
    for(auto v: adj[node])
    {
        if(!visited[v])toposort(v,adj,visited,st);
    }
    st.push(node);
}
void scc(ll node,vector<vector<ll>>&adjT,vector<bool>&visited1,vector<ll>&cost, ll &mincost, ll &ways)
{
    visited1[node]=true;
    if(mincost>cost[node])
    {
        mincost=cost[node];
        ways=1;
    }
    else if(mincost==cost[node])
    {
        ways++;
    }
    for(auto v: adjT[node])
    {
        if(!visited1[node])scc(v,adjT,visited1,mincost,ways);
    }
}
void muhtasim()
{
  ll n,m;
  cin>>n>>m;
  vector<ll>cost(n);
  for(int i=0;i<n;i++)cin>>cost[i];
  vector<vector<ll>>adj(n);
  for(int i=0;i<m;i++)
  {
    ll u,v;
    cin>>u>>v;
    adj[u-1].push_back(v-1);
  }  
  vector<bool>visited(n,false);
  stack<ll>st;
  for(int i=0;i<n;i++)
  {
    if(!visited[i])toposort(i,adj,visited,st);
  }
  vector<ll>seq;
  while(!st.empty())
  {
    seq.push_back(st.top());
    st.pop();
  }
  vector<bool>visited1(n,false);
  vector<vector<ll>>adjT(n);
  for(int i=0;i<n;i++)
  {
    for(auto v: adj[i])
    {
        adjT[v].push_back(i);
    }
  }
  ll total=0,totalways=1;
  for(int i=0;i<seq.size();i++)
  {
    if(!visited1[seq[i]])
    {
        ll ways=0,mincost=LLONG_MAX;
        scc(seq[i],adjT,visited1,cost,mincost,ways);
        total+=mincost;
        totalways=(totalways*ways)%(1e9+7);

    }
  }
  cout<<total<<" "<<totalways<<"\n";
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