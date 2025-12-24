class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        vector<int> altitude;
        altitude.push_back(0);
        for (auto x : gain)
        {
            altitude.push_back(altitude.back() + x);
        }
        return *max_element(altitude.begin(), altitude.end());
    }
};