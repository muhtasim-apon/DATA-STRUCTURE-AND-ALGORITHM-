class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        int centre = 0;
        for (int i = 0; i < edges.size() - 1; i++)
        {
            if (edges[i][0] == edges[i + 1][0])
                centre = edges[i][0];
            else if (edges[i][0] == edges[i + 1][1])
                centre = edges[i][0];
            else if (edges[i][1] == edges[i + 1][0])
                centre = edges[i + 1][0];
            else
                centre = edges[i + 1][1];
        }
        return centre;
    }
};