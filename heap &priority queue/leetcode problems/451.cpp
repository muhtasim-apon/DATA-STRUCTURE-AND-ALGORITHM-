class Solution
{
public:
    // priority_queue<pair<int,char>>pq;
    // map<char,int>freq;
    string frequencySort(string s)
    {
        string ans = "";
        priority_queue<pair<int, char>> pq;
        map<char, int> freq;
        for (auto c : s)
            freq[c]++;
        for (auto x : freq)
            pq.push({x.second, x.first});
        freq.clear();
        while (!pq.empty())
        {
            int a = pq.top().first;
            ans.append(a, pq.top().second);
            pq.pop();
        }
        // reverse(ans.begin(),ans.end());
        return ans;
    }
};