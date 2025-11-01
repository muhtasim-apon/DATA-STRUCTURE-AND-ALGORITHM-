#include <bits/stdc++.h>
using namespace std;
long int factorial(long int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}
long int fibonacci(long int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
void printfibonacci(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << fibonacci(i) << " ";
    }
    cout << "\n";
}
int main()
{
    printf("Input:\n");
    long int n;
    scanf("%lld", &n);
    long int fact = factorial(n);
    printf("Output:\n");
    printf("Factorial=");
    cout << fact << "\n";
    printf("Fibonacci= ");
    printfibonacci(n);
}