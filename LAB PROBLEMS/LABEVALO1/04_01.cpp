#include <bits/stdc++.h>
using namespace std;

// Returns first index i in [L,R] such that A[i] >= x
int lowerBound(vector<int> &A, int L, int R, int x)
{
    int l = L, r = R, ans = R + 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (A[m] >= x)
        {
            ans = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return ans;
}

// Returns last index i in [L,R] such that A[i] <= x
int upperBound(vector<int> &A, int L, int R, int x)
{
    int l = L, r = R, ans = L - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (A[m] <= x)
        {
            ans = m;
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return ans;
}

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    int Q;
    cin >> Q;
    while (Q--)
    {
        int x, L, R;
        cin >> x >> L >> R;

        int left = lowerBound(A, L, R, x);
        int right = upperBound(A, L, R, x);

        if (left <= right && left >= L && right <= R)
        {
            // x exists in range
            cout << left << " " << right << "\n";
        }
        else
        {
            // x does not exist
            // Find nearest i < x and j > x in [L,R]
            int i = left - 1;
            int j = left;

            if (i < L)
                i = -1;
            if (j > R)
                j = -1;

            cout << i << " " << j << "\n";
        }
    }

    return 0;
}
