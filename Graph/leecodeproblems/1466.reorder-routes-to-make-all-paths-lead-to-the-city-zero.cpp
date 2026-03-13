class Solution {
    void dfs(int u,vector<vector<int>>&adj1,vector<vector<int>>&adj2,vector<bool>&visited,int &count)
    {
        visited[u]=true;
        for(auto v:adj2[u])
        {
            if(!visited[v])
            {
                //parent[v]=u;
                if(find(adj1[u].begin(),adj1[u].end(),v)!=adj1[u].end())count++;
                dfs(v,adj1,adj2,visited,count);
            }
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj1(n);//directed
        vector<vector<int>>adj2(n); //undirected
        for(int i=0;i<connections.size();i++)
        {
            adj1[connections[i][0]].push_back(connections[i][1]);
            adj2[connections[i][0]].push_back(connections[i][1]);
            adj2[connections[i][1]].push_back(connections[i][0]);
        }
        vector<bool>visited(n,false);
        int count=0;
        //map<int,int>parent;
        //parent[0]=-1;
        dfs(0,adj1,adj2,visited,count);
        return count;
    }
};