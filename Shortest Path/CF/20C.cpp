#include<bits/stdc++.h>
#define ll long long
using namespace std;
void muhtasim()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>>adj(n);
    vector<bool>visited(n,false);
    vector<ll>dist(n,LLONG_MAX);
    map<ll,ll>parent;
    vector<ll>ans;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    for(int i=1;i<=m;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u-1].push_back({v-1,w});
        adj[v-1].push_back({u-1,w});
    }
    dist[0]=0;
    pq.push({0,0});
    parent[0]=-1;
    //seq.push_back(1);
    int done =false;
    while(!pq.empty())
    {
        ll v=pq.top().second;
        //seq.push_back(pq.top().second+1);
        pq.pop();
        if(visited[v])continue;
        visited[v]=true;
        for(auto it : adj[v] )
        {
            if(!visited[it.first] && dist[v]+it.second<dist[it.first])
            {
                dist[it.first]=dist[v]+it.second;
                pq.push({dist[it.first],it.first});
                parent[it.first]=v;
               // seq.push_back(it.first+1);
               
            }
        }
       // if(done)break;
    }
    if(dist[n-1]!=LLONG_MAX)
    {
        ans.push_back(n);
        ll v=parent[ans.back()-1];
        while(v!=-1)
        {
           // ll v=parent[ans.back()-1];
            ans.push_back(v+1);
            v=parent[v];
        }
        reverse(ans.begin(),ans.end());
        for(auto it: ans)
        {
            cout<<it<<" ";
        }
    }
    else cout<<-1;

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