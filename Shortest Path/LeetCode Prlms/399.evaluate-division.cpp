class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        set<string>s;
        for(int i=0;i<equations.size();i++)
        {
            s.insert(equations[i][0]);
            s.insert(equations[i][1]);
        }
        int n=s.size();
        vector<vector<long double>>closure(n,vector<long double>(n,-1.0));
        map<string,int>mp;
        int i=0;
        for(auto x:s)
        {
            mp[x]=i;
            i++;
        }
        for(int i=0;i<equations.size();i++)
        {
            closure[mp[equations[i][0]]][mp[equations[i][1]]]=values[i];
            closure[mp[equations[i][1]]][mp[equations[i][0]]]=1/(long double)values[i];
        }
        for(long double i=0;i<n;i++)
        {
            for(long double j=0;j<n;j++)
            {
                if(i==j)closure[i][j]=1.0;
            }
        }
        for(long double k=0;k<n;k++)
        {
            for(long double i=0;i<n;i++)
            {
                for(long double j=0;j<n;j++)
                {
                    if(closure[i][k]!=-1.0 && closure[k][j]!=-1.0)
                    {
                        closure[i][j]=closure[i][k]*closure[k][j];
                    }
                }
            }
        }
        vector<double>ans;
        for(int i=0;i<queries.size();i++)
        {
            if(s.count(queries[i][0]) && s.count(queries[i][1]))
            {
                ans.push_back(closure[mp[queries[i][0]]][mp[queries[i][1]]]);
            }
            else ans.push_back(-1.0);
        }
        return ans;
    }
};