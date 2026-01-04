#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int A[N];

    for (int i = 0; i < N; i++)
        cin >> A[i];

    // Count inversions
    int inversions = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (A[i] > A[j])
                inversions++;
        }
    }

    // Sort array using bubble sort
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(A[j], A[j + 1]);
            }
        }
    }

    // Print sorted array
    for (int i = 0; i < N; i++)
        cout << A[i] << (i == N - 1 ? "\n" : " ");

    // Print inversion parity
    cout << (inversions % 2 == 0 ? "Even" : "Odd") << "\n";

    return 0;
}
