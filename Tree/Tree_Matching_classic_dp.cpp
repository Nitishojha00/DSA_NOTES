#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 200001;
vector<int> tree[MAXN];

// Returns pair: {max_matching_if_node_not_matched, max_matching_if_node_matched}
pair<int, int> dfs(int node, int parent) {
    int not_matched = 0;  // dp[0]
    int matched = 0;      // dp[1]

    for (int child : tree[node]) {
        if (child == parent) continue;

        auto child_dp = dfs(child, node);

        // If current node is not matched:
        // We can take the best of child's matched or not matched state
        not_matched += max(child_dp.first, child_dp.second);

        // If current node is matched, it must be matched with exactly one child:
        // We try three options to update matched:
        // 1) match current node with this child:
        //    current not_matched + child's not_matched + 1 edge (between node and child)
        // 2) keep previously calculated matched plus child's matched
        // 3) keep previously calculated matched plus child's not_matched
        matched = max({
            matched + child_dp.second,
            matched + child_dp.first,
            not_matched - max(child_dp.first, child_dp.second) + child_dp.first + 1
        });
    }

    return {not_matched, matched};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int u, v; 
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    auto result = dfs(1, -1);
    cout << max(result.first, result.second) << '\n';

    return 0;
}
