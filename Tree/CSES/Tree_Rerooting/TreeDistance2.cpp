//Rerooting Concept
 
// steps
//step1 -> find subordinate simple for every node
// step2-> finding answer for root node 
// step 3 -> using answer for root node finding answer for others

#include <iostream>
#include <vector>
using namespace std;
 
using ll = long long;
const int N = 200001;
 
int n;
vector<int> g[N];
int subtree[N];     // Size of subtree rooted at each node
ll ans[N];          // Answer for each node: sum of distances
 
// ✅ STEP 1: Separate function to compute only subtree sizes
void calculateSubtreeSize(int node, int parent) {
    subtree[node] = 1;
 
    for (int child : g[node]) {
        if (child == parent) continue;
        calculateSubtreeSize(child, node);
        subtree[node] += subtree[child];
    }
}
 
// ✅ STEP 2: Separate DFS to calculate distance sum from node 1 only
void calculateDistanceFromRoot(int node, int parent, int depth, ll &sum) {
    sum += depth;
 
    for (int child : g[node]) {
        if (child == parent) continue;
        calculateDistanceFromRoot(child, node, depth + 1, sum);
    }
}
 
// ✅ STEP 3: Re-rooting to find distances for all nodes
void rerootDFS(int node, int parent) {
    for (int child : g[node]) {
        if (child == parent) continue;
 
        // Re-rooting formula
        ans[child] = ans[node] - subtree[child] + (n - subtree[child]);
        rerootDFS(child, node);
    }
}
 
int main() {
    cin >> n;
 
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
 
    // STEP 1: Calculate subtree sizes
    calculateSubtreeSize(1, 1);
 
    // STEP 2: Calculate distance sum from root (node 1)
    ll sum = 0;
    calculateDistanceFromRoot(1, 1, 0, sum);
    ans[1] = sum;
 
    // STEP 3: Re-root to calculate for all other nodes
    rerootDFS(1, 1);
 
    // Output
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}