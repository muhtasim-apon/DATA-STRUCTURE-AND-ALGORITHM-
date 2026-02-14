class Solution
{
public:
    void dfs(int node, vector<vector<int>> &isConnected, vector<int> &visited)
    {
        if (!visited[node])
        {
            visited[node] = 1;
            for (int i = 0; i < isConnected.size(); i++)
            {
                if (!visited[i] && isConnected[node][i])
                    dfs(i, isConnected, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        // vector<vector<int>>adjlist(n,vector<int>(n));
        vector<int> visited(n, 0);
        // //making a adjacency list
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         if(isConnected[i][j] && i!=j)
        //         {
        //             adjlist[i].push_back(j);
        //             adjlist[j].push_back(i);
        //         }
        //     }
        // }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                ans++;
                dfs(i, isConnected, visited);
            }
        }
        return ans;
    }
};