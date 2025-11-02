// Problem B
// Input:
// First line: n, a number (1<=n<=10).
// Output:
// Each line will contain a list of space-separated digits where,
// ● The list contains n digits.
// ● The digits in the list are 0-4 (inclusive)
// ● The odd indexed digit in the list is an even digit
// ● The even indexed digit in the list is an odd digit
// The lists will be printed in descending order. Example: {1 0 3} before {1 0 1}.
// Sample Case:
// Input Output
// 2 3 4
// 3 2
// 3 0
// 1 4
// 1 2
// 1 0
// 3 3 4 3
// 3 4 1
// 3 2 3
// 3 2 1
// 3 0 3
// 3 0 1
// 1 4 3
// 1 4 1
// 1 2 3
// 1 2 1
// 1 0 3
// 1 0 1
#include <bits/stdc++.h>
using namespace std;
int n,m;
void generatelist(vector<int>&a,int idx,int n)
{
    if(idx==n)
    {
        for(int i=0;i<n;i++)
        {
            if(i)cout<<" ";
            cout<<a[i];
        }
        cout<<"\n";
        return;
    }
    if(idx%2==0)
    {
        for(int i=m;i>=0;i-=2)
        {
            a[idx]=i;
            generatelist(a,idx+1,n);
        }
    }
    else
    {
        for(int i=m-1;i>=0;i-=2)
        {
            a[idx]=i;
            generatelist(a,idx+1,n);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    m=4;
    vector<int>a(n);
    generatelist(a,0,n);
    return 0;
}