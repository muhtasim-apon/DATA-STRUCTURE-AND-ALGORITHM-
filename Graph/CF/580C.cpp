#include <bits/stdc++.h>
#define ll long long
using namespace std;
void dfs(ll u, vector<vector<ll>> &adj, vector<bool> &visited, ll &consecutive, ll &ans, ll &m, map<ll, ll> &cat)
{
    ll old = consecutive;
    visited[u] = true;
    bool leaf = true;
    // sum += cat[u];
    if (cat[u] == 1)
        consecutive++;
    else
        consecutive = 0;
    if (consecutive > m)
    {
        consecutive = old;
        return;
    }
    for (auto v : adj[u])
    {
        if (!visited[v])
        {
            leaf = false;
            dfs(v, adj, visited, consecutive, ans, m, cat);
        }
    }
    // cout << u << " ";
    //  cout << "\n";
    // cout << sum << "\n";
    // bool leaf = true;
    // for (auto v : adj[u])
    // {
    //     if (!visited[v])
    //         // cout << consecutive << "\n";
    //         bool leaf = false;
    // }
    // while (parent[u] != -1)
    // {
    //     ll count = 0;
    //     while (cat[u] == 1)
    //     {
    //         count++;
    //         if (count > m)
    //         {
    //             test = false;
    //         }
    //         u = parent[u];
    //     }
    //     u = parent[u];
    // }
    // if (consecutive <= m)
    //     test = true;
    if (leaf)
        ans++;
    consecutive = old;
    // cout << u << "\n";
}
// cout << sum << "\n";
// sum -= cat[u];
void muhtasim()
{
    ll n, m;
    cin >> n >> m;
    map<ll, ll> cat;
    vector<int> v(n);
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        cat[i] = v[i];
    }
    ll sum = 0, ans = 0;
    vector<vector<ll>> adj(n);
    // map<ll, ll> parent;
    // parent[0] = -1;
    ll consecutive = 0;
    for (int i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        // parent[v - 1] = u - 1;
        adj[v - 1].push_back(u - 1);
    }
    dfs(0, adj, visited, consecutive, ans, m, cat);
    std::cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll tests = 1;
    // cin>>tests;
    while (tests--)
    {
        muhtasim();
    }
}