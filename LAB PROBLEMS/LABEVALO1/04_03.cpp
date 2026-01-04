#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    stack<int> S;
    queue<int> Q;
    int ops = 0;

    vector<int> input(N);
    for (int i = 0; i < N; i++)
        cin >> input[i];

    // Push input into stack (bottom to top)
    for (int i = 0; i < N; i++)
    {
        S.push(input[i]);
        ops++; // push
    }

    // Sort stack using queue
    for (int sorted = 0; sorted < N; sorted++)
    {
        int size = S.size();
        int minVal = INT_MAX;

        // Move all elements from stack to queue, find min
        for (int i = 0; i < size; i++)
        {
            int val = S.top();
            S.pop();
            ops++; // pop
            Q.push(val);
            ops++; // enqueue
            if (val < minVal)
                minVal = val;
        }

        // Move back all elements except min
        int qSize = Q.size();
        bool minUsed = false;
        for (int i = 0; i < qSize; i++)
        {
            int val = Q.front();
            Q.pop();
            ops++; // dequeue
            if (val == minVal && !minUsed)
            {
                // This will go to stack later
                minUsed = true;
                continue;
            }
            S.push(val);
            ops++; // push
        }

        // Push the min to stack (smallest goes on top)
        S.push(minVal);
        ops++;
    }

    // Print stack from bottom to top
    vector<int> out;
    while (!S.empty())
    {
        out.push_back(S.top());
        S.pop();
        ops++;
    }
    reverse(out.begin(), out.end());
    for (int i = 0; i < N; i++)
        cout << out[i] << (i == N - 1 ? "\n" : " ");

    // Print total operations
    cout << ops << "\n";

    return 0;
}
