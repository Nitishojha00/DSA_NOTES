//used dfs + greedy its deasigned by me 
//greedy kaisa  dp me to all the way dhekna padta 
// initialised array with 1 indicating that 1 self 1 node
// 1-2,2-3,3-4,4-5  we start traversing when we are returning from the leaf node 
//  their is two option 
// option 1 -> only one child/neib ->  a[node] += a[neib]   (simple)
// option 2-> more than 1 child 2,3,4,5 ..whatever we face some situation
//  for all child we do a[node] += a[neib]
//  but we also count odd number of child example -> 1-2,1-3,1-4,3-5,5-6  at node 1 i get  
// a[1] += a[2] -> a[2] = 1
// a[1]+= a[3]  -> a[3] = 3 -> 3,5,6
// a[1] += a[4] -> a[4] = 1
// 3 odd then we can make maximum one pair with node 1 choose any its not effect answer 
// that why i am subtracting  a[node] -= (odd_count - 1);


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
