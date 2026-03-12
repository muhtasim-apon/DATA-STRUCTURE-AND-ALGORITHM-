class Solution {
    // void toposort(int node,vector<vector<int>>&adj,vector<bool>&visited,stack<int>&st)
    // {
    //     visited[node]=true;
    //     for(auto v: adj[node])
    //     {
    //         if(!visited[v])toposort(v,adj,visited,st);
    //     }
    //     st.push(node);

    // }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // vector<vector<int>>adj(numCourses);
        // for(int i=0;i<prerequisites.size();i++)
        // {
        //     adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        // }
        // stack<int>st;
        // vector<bool>visited(numCourses,false);
        // for(int i=0;i<numCourses;i++)
        // {
        //    if(!visited[i]) toposort(i,adj,visited,st);
        // }
        // vector<int>seq;
        // while(!st.empty())
        // {
        //     seq.push_back(st.top());
        //     st.pop();
        // }
        // for(int i=0;i<seq.size();i++)cout<<seq[i]<<" ";
        // cout<<"\n";
        // vector<bool>ans;
        // if(prerequisites.size()==0)
        // {
        //     for(int i=0;i<queries.size();i++)
        //     {
        //         ans.push_back(false);
        //     }
        //     return ans;
        // }
        // for(int i=0;i<queries.size();i++)
        // {
        //     auto a=find(seq.begin(),seq.end(),queries[i][0]);
        //     auto b=find(seq.begin(),seq.end(),queries[i][1]);
        //     if(a<b) ans.push_back(true);
        //     else ans.push_back(false);
        // }
        // return ans;
        vector<vector<bool>>closure(numCourses,vector<bool>(numCourses,false));
        for(int i=0;i<prerequisites.size();i++)
        {
            closure[prerequisites[i][0]][prerequisites[i][1]]=true;
        }
        for(int k=0;k<numCourses;k++)
        {
            for(int i=0;i<numCourses;i++)
            {
                for(int j=0;j<numCourses;j++)
                {
                    if(closure[i][k] && closure[k][j])
                    {
                        closure[i][j]=true;
                    }
                }
            }
        }
        vector<bool>ans;
        for(int i=0;i<queries.size();i++)
        {
            if(closure[queries[i][0]][queries[i][1]])ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};