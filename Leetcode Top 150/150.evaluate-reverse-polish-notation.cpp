class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        for (auto x : tokens)
        {
            if (x == "+" || x == "-" || x == "*" || x == "/")
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int c;
                if (x == "+")
                    c = a + b;
                else if (x == "-")
                    c = b - a;
                else if (x == "*")
                    c = a * b;
                else
                    c = b / a;
                st.push(c);
            }
            else
            {
                int v = stoi(x);
                st.push(v);
            }
        }
        return st.top();
    }
};