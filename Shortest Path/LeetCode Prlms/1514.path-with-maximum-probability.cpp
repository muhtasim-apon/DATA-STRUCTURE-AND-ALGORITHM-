class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>>adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<double,int>,vector<pair<double,int>>>pq;
        vector<double>prob(n,LLONG_MIN);
        vector<bool>visited(n,false);
        prob[start_node]=1;
        pq.push({prob[start_node],start_node});
        while(!pq.empty())
        {
            auto u=pq.top();
            pq.pop();
            if(visited[u.second])continue;
            visited[u.second]=true;
            for(auto v : adj[u.second]){
                if(!visited[v.first] && prob[u.second]*v.second>prob[v.first])
                {
                    prob[v.first]=prob[u.second]*v.second;
                    pq.push({prob[v.first],v.first});
                }
            }
        }
            if(prob[end_node]==LLONG_MIN)return 0;
            else return prob[end_node];
        }

};