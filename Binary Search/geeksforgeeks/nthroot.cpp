#include <bits/stdc++.h>
using namespace std;

// Function to compute x^n
double power(double x, int n)
{
    double result = 1;
    for (int i = 0; i < n; i++)
        result *= x;
    return result;
}

// Function to find nth root of num using binary search
double nthRoot(double num, int n, double eps = 1e-6)
{
    double low = 0;
    double high = max(1.0, num); // handle num < 1
    double mid;

    while (high - low > eps)
    {
        mid = (low + high) / 2.0;
        if (power(mid, n) < num)
            low = mid;
        else
            high = mid;
    }

    return (low + high) / 2.0;
}

int main()
{
    double num;
    int n;
    cout << "Enter number and root n: ";
    cin >> num >> n;

    double root = nthRoot(num, n);
    cout << "The " << n << "-th root of " << num << " is approximately " << root << endl;

    return 0;
}
