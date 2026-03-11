class Solution {
public:

    int dijkstra(int src,vector<vector<pair<int,int>>>&adj,int &distanceThreshold,int n )
    {
        vector<int>dist(n,INT_MAX);
        vector<bool>visited(n,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[src]=0;
        pq.push({0,src});
        while(!pq.empty())
        {
            auto u=pq.top();
            pq.pop();
            if(visited[u.second])continue;
            visited[u.second]=true;
            for(auto it : adj[u.second])
            {
                if(dist[u.second]+it.second<dist[it.first])
                {
                    dist[it.first]=dist[u.second]+it.second;
                    pq.push({dist[it.first],it.first});
                }
            }
        }
            int count=0;
            for(auto x: dist)
            {
                if(x==0)continue;
                else if(x<=distanceThreshold)count++;
            }
            return count;

    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            int cities=dijkstra(i,adj,distanceThreshold,n);
            ans.push_back(cities);
        }
        int maxcity=1e9;
        int finalans=-1;
        for(auto x : ans)
        {
            cout<<x<<" ";
        }
        cout<<"\n";
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]<=maxcity)
            {
                maxcity=ans[i];
                finalans=i;
            }
        }
        return finalans;
    }
};