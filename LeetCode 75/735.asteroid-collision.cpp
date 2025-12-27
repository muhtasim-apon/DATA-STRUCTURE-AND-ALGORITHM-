class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> st;
        int a;
        for (auto x : asteroids)
        {
            if (x >= 0)
                st.push(x);
            else
            {
                if (st.empty() || st.top() < 0)
                    st.push(x);
                else
                {
                    while (!st.empty() && st.top() >= 0)
                    {
                        a = st.top();
                        if (abs(x) > st.top())
                        {
                            st.pop();
                        }
                        else if (st.top() == abs(x))
                        {
                            st.pop();
                            break;
                        }
                        else if (st.top() > abs(x))
                            break;
                    }
                    if (a < abs(x))
                        st.push(x);
                }
            }
        }
        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};