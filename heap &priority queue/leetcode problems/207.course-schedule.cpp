class Solution
{
    bool iscycle(int u, vector<vector<int>> &edges, vector<bool> &visited, vector<bool> &recurpath)
    {
        visited[u] = true;
        recurpath[u] = true;
        for (auto v : edges[u])
        {
            if (!visited[v])
            {
                if (iscycle(v, edges, visited, recurpath))
                    return true;
            }
            else if (recurpath[v])
                return true;
        }
        recurpath[u] = false;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<bool> visited(numCourses, false);
        vector<bool> recurpath(numCourses, false);
        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i])
            {
                if (iscycle(i, adj, visited, recurpath))
                    return false;
            }
        }
        return true;
    }
};