// Input:
// First line: n, a number (1<=n<=10).
// Output:
// Each line will contain a list of space-separated digits where,
// ● The list contains n digits.
// ● The digits in the list are 0-4 (inclusive)
// ● The odd indexed digit in the list is an odd digit
// ● The even indexed digit in the list is an even digit
// The lists will be printed in sorted order. Example: {0, 1, 0} before {0, 1, 2}.
// Sample Case:
// Input Output
// 2 0 1
// 0 3
// 2 1
// 2 3
// 4 1
// 4 3
// 3 0 1 0
// 0 1 2
// 0 1 4
// 0 3 0
// 0 3 2
// 0 3 4
// 2 1 0
// 2 1 2
// 2 1 4
// 2 3 0
// 2 3 2
// 2 3 4
// 4 1 0
// 4 1 2
// 4 1 4
// 4 3 0
// 4 3 2
// 4 3 4
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
        for(int i=0;i<=4;i+=2)
        {
            a[idx]=i;
            generatelist(a,idx+1,n);
        }
    }
    else
    {
        for(int i=1;i<=4;i+=2)
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