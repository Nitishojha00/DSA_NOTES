//  Next we will discuss two O(n) time algorithms for calculating the diameter
 //of a tree. The first algorithm is based on dynamic programming, and the second
// algorithm uses two depth-first searches we use 2 method to solve that problem

 #include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using Graph = vector<vector<ll>>;

void dfs(const Graph& adj, ll node, ll parent, vll& depth) {
    for (ll neighbor : adj[node]) {
        if (neighbor == parent) continue;
        depth[neighbor] = depth[node] + 1;
        dfs(adj, neighbor, node, depth);
    }
}

ll find_farthest(const Graph& adj, ll start, vll& depth_out) {
    ll n = adj.size();
    depth_out.assign(n, 0);
    dfs(adj, start, -1, depth_out);
    
    ll farthest = start;
    for (ll i = 0; i < n; ++i) {
        if (depth_out[i] > depth_out[farthest]) {
            farthest = i;
        }
    }
    return farthest;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }

    Graph adj(n);
    for (ll i = 0; i < n - 1; ++i) {
        ll u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vll depth;
    ll r1 = find_farthest(adj, 0, depth);       // first endpoint of diameter
    ll r2 = find_farthest(adj, r1, depth);      // second endpoint of diameter

    vll d1, d2;
    dfs(adj, r1, -1, d1 = vll(n, 0));
    dfs(adj, r2, -1, d2 = vll(n, 0));

    for (ll i = 0; i < n; ++i)
        cout << max(d1[i], d2[i]) << " ";
    
    cout << '\n';
    return 0;
}
