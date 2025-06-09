#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr)

using ll = long long;
using vll = vector<ll>;

vector<vll> adj;
ll diameter = 0;

ll dfs(ll node, ll parent) {
    ll max1 = 0, max2 = 0;

    for (ll neighbor : adj[node]) {
        if (neighbor == parent) continue;

        ll depth = dfs(neighbor, node);
        if (depth > max1) {
            max2 = max1;
            max1 = depth;
        } else if (depth > max2) {
            max2 = depth;
        }
    }

    // Update diameter: path through this node
    diameter = max(diameter, max1 + max2);

    return max1 + 1;
}

void solve() {
    ll n;
    cin >> n;

    adj.assign(n + 1, {});
    for (ll i = 0; i < n - 1; ++i) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);
    cout << diameter << '\n'; // edges in the longest path
}

int main() {
    FAST_IO;
    solve();
    return 0;
}
