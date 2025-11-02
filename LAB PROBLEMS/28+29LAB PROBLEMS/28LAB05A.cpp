// Problem A

// Input:
// First line: n, a number (1<=n<=15).
// Second line: k, a number (1<=k<=n).
// Output:
// Print all possible combinations of k digits from (0-n) in descending order.
// Sample Case:
// Input Output
// 5
// 3

// 4 3 2
// 4 3 1
// 4 3 0
// 4 2 1
// 4 2 0
// 4 1 0
// 3 2 1
// 3 2 0
// 3 1 0
// 2 1 0
#include <bits/stdc++.h>
using namespace std;
int n, k;
void backtrack(int start, vector<int> &comb) {
    if (comb.size() == k) {
        for (int i = 0; i < k; i++) {
            cout << comb[i] << (i == k - 1 ? "\n" : " ");
        }
        return;
    }
    for (int i = start; i >= 0; i--) {
        comb.push_back(i);
        backtrack(i - 1, comb);
        comb.pop_back();
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    vector<int> comb;
    backtrack(n - 1, comb);
    return 0;
}