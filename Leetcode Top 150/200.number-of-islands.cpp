class Solution
{
public:
    int islands;
    void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &visited, int n, int m)
    {
        if (i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || grid[i][j] == '0')
            return;
        visited[i][j] = true;
        dfs(i - 1, j, grid, visited, n, m);
        dfs(i + 1, j, grid, visited, n, m);
        dfs(i, j + 1, grid, visited, n, m);
        dfs(i, j - 1, grid, visited, n, m);
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    dfs(i, j, grid, visited, n, m);
                    islands++;
                }
            }
        }
        return islands;
    }
};