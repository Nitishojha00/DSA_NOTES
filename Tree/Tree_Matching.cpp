//used dfs + greedy its deasigned by me 
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;


// DFS function to update node values
void dfs(vector<vll> &adj, ll node, ll parent, vll &a) 
{
     int odd_count = 0;

    for (ll neighbor : adj[node]) 
    {
        if (neighbor == parent) continue;

        dfs(adj, neighbor, node, a);
         if (a[neighbor] % 2 != 0) odd_count++;
         a[node]+=a[neighbor];
    }

    if (odd_count > 1) 
      a[node] -= (odd_count - 1);
   
}

// Solve function for the test case
void solve() 
{
    ll n;
    cin >> n;

    vector<vll> adj(n + 1);
    for (ll i = 0; i < n - 1; ++i) 
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vll a(n + 1, 1);  // Initialize each node's value to 1
    dfs(adj, 1, -1, a);

    cout << a[1] / 2 << '\n';
}

// Main function
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
