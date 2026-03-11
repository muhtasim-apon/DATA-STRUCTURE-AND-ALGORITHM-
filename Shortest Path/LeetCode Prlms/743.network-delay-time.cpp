class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n,INT_MAX);
        vector<bool>visited(n,false);
        for(int i=0;i<times.size();i++)
        {
            adj[times[i][0]-1].push_back({times[i][1]-1,times[i][2]});
        }
        dist[k-1]=0;
        pq.push({0,k-1});
        while(!pq.empty())
        {
            auto current=pq.top();
            pq.pop();
            if(visited[current.second])continue;
            visited[current.second]=true;
            for(auto it:adj[current.second])
            {
                if(!visited[it.first])
                {
                    if(dist[current.second]+it.second<dist[it.first])
                    {
                        dist[it.first]=dist[current.second]+it.second;
                        pq.push({dist[it.first],it.first});
                    }
                }
            }

        }
          if(find(dist.begin(),dist.end(),INT_MAX)!=dist.end())return -1;
        else return *max_element(dist.begin(),dist.end());

    }
};