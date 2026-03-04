class Solution
{
public:
    void dfs(int u, vector<vector<int>> &adj, vector<bool> &visited, set<int> &ans)
    {
        visited[u] = true;
        ans.insert(u);
        for (auto v : adj[u])
        {
            if (!visited[v])
                dfs(v, adj, visited, ans);
        }
    }
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int n = rooms.size();
        vector<vector<int>> adj(n);
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < rooms[i].size(); j++)
            {
                if (rooms[i].size() != 0)
                {
                    adj[k].push_back(rooms[i][j]);
                }
            }
            k++;
        }
        set<int> ans;
        vector<bool> visited(n, false);
        dfs(0, adj, visited, ans);
        // cout<<n<<"\n";
        // for(auto x: ans)cout<<x<<" ";
        // cout<<"\n";
        if (ans.size() == n)
            return true;
        return false;
    }
};