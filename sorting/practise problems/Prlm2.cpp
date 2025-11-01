// In this problem, you will be given n numbers. There is a window of size k which is
// moving from left to right. You will have to report the sum of the windows.
// Input:
// First line: n, a number (1<=n<=10^6).
// Second line: k, a number (1<=k<=n).
// Next n lines: vi, a number (-1000<= vi <=1000).
// Output:
// Each line will contain the sum of the windows from left to right.
// Sample Case:
// Input Output
// 5
// 2
// 1
// 2
// 3
// 4
// 5

// 3
// 5
// 7
// 9

// Explanation:
// Here the window size is 2. The leftmost window contains 1 and 2. The sum is 3.
// Hence, 3 goes to output.
// In the next step, the window shifts to right and the items are 2 and 3. The sum is 5. 
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    long long window_sum=0;
    for(int i=0;i<k;i++)
    {
        window_sum+=v[i];
    }
    cout<<window_sum<<"\n";
    for(int i=k;i<n;i++)
    {
        window_sum+=v[i]-v[i-k];
        cout<<window_sum<<"\n";
    }
    return 0;
}