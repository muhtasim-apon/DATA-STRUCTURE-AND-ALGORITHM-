class Solution
{

    void topologicalsort(int u, vector<bool> &visited1, vector<vector<int>> &adj, stack<int> &topo)
    {
        visited1[u] = true;
        for (auto v : adj[u])
        {
            if (!visited1[v])
            {
                topologicalsort(v, visited1, adj, topo);
                // topo.push(v);
            }
        }
        topo.push(u);
    }
    bool iscycle(int u, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &recurpath)
    {
        visited[u] = true;
        recurpath[u] = true;
        for (auto v : adj[u])
        {
            if (!visited[v])
            {
                if (iscycle(v, adj, visited, recurpath))
                    return true;
            }
            else if (recurpath[v])
                return true;
        }
        recurpath[u] = false;
        return false;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> ans;
        bool test = false;
        vector<bool> visited(numCourses, false);
        vector<bool> recurpath(numCourses, false);
        stack<int> topo;
        for (int i = 0; i < numCourses; i++)
        {
            if (iscycle(i, adj, visited, recurpath))
                test = true;
        }
        if (test)
            return ans;
        else
        {
            vector<bool> visited1(numCourses);
            for (int i = 0; i < numCourses; i++)
            {
                if (!visited1[i])
                    topologicalsort(i, visited1, adj, topo);
            }
            while (!topo.empty())
            {
                ans.push_back(topo.top());
                topo.pop();
            }
        }
        return ans;
    }
};