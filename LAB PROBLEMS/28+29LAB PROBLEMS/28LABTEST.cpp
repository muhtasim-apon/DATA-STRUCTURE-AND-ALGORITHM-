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
    for (int i = start; i<n; i++) {
        comb.push_back(i);
        backtrack(i + 1, comb);
        comb.pop_back();
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    vector<int> comb;
    backtrack(0, comb);
    return 0;
}