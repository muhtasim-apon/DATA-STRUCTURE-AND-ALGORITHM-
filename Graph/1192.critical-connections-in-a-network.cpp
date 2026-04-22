class Solution {
public:
    void dfs(int node, vector<bool>&visited,vector<vector<int>>&edges,int &time,vector<int>&start,vector<int>&low,vector<vector<int>>&bridges,int parent)
    {
        visited[node]=true;
        start[node]=time;
        low[node]=time;
        time++;
        //int child=0;
        for(auto it : edges[node])
        {
            if(it==parent)continue;
            if(!visited[it])
            {
                dfs(it,visited,edges,time,start,low,bridges,node);
                low[node]=min(low[node],low[it]);
                if(low[it]>start[node])bridges.push_back(vector<int>{node,it});
            }
            else
            {
                low[node]=min(low[node],start[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>edges(n);
        vector<vector<int>>bridges;
        vector<int>start(n),low(n);
        vector<bool>visited(n,false);
        int time=0;
        for(int i=0;i<connections.size();i++)
        {
            edges[connections[i][0]].push_back(connections[i][1]);
            edges[connections[i][1]].push_back(connections[i][0]);
        }
        int parent=-1;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])dfs(i,visited,edges,time,start,low,bridges,parent);
        }
        return bridges;
    }
};