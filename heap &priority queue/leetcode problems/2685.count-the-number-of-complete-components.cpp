class Solution
{
    void dfs(int u, vector<vector<int>> &adj, vector<bool> &visited, int &vertex, int &edges)
    {
        visited[u] = true;
        vertex++;
        if (adj[u].size() > 0)
            edges += adj[u].size();
        for (auto v : adj[u])
            adj[v].erase(find(adj[v].begin(), adj[v].end(), u));
        for (auto v : adj[u])
        {
            if (!visited[v])
                dfs(v, adj, visited, vertex, edges);
        }
    }

public:
    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n);
        int ans = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                int vertex = 0;
                int edges = 0;
                dfs(i, adj, visited, vertex, edges);
                if (edges * 2 == (vertex) * (vertex - 1))
                    ans++;
            }
        }
        return ans;
    }
};