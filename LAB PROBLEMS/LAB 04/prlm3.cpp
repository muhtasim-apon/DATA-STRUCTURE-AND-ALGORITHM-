#include <bits/stdc++.h>
using namespace std;
long int sum(long int arr[], int n)
{

    if (n == 0)
        return 0;
    return arr[n - 1] + sum(arr, n - 1);
}

int main()
{
    long int n;
    cout << "Enter Size of Array:\n";
    cin >> n;
    printf("Input:\n");
    long int array[n];
    for (int i = 0; i < n; i++)
        cin >> array[i];
    long int s = sum(array, n);
    printf("Output:\n");
    cout << s << "\n";
}