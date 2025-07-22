class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& vis, int node){
        vis[node] = true;
        for(int adjnode : adj[node]){
            if(!vis[adjnode])
                dfs(adj, vis, adjnode);
        }
    }

    bool check(vector<vector<pair<int,int>>>& graph, long long mid, int k){
        int n = graph.size();
        vector<vector<int>> adj(n);

        for(int i = 0; i < n; i++){
            for(auto x : graph[i]){
                int adjnode = x.first, wt = x.second;
                if(wt <= mid){
                    adj[i].push_back(adjnode);
                }
            }
        }

        vector<bool> vis(n, false);
        int components = 0;

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                components++;
                dfs(adj, vis, i);
            }
        }

        return components <= k;
    }

    int minCost(int n, vector<vector<int>>& edges, int k) {
        if (n == 0) return 0;
        if (edges.empty()) return (n <= k) ? 0 : -1;

        vector<vector<pair<int,int>>> graph(n);
        int low = 0, high = 0, ans = -1;

        for(auto& edge : edges){
            int u = edge[0], v = edge[1], wt = edge[2];
            graph[u].push_back({v, wt});
            graph[v].push_back({u, wt});
            high = max(high, wt);
        }

        while(low <= high){
            long long mid = (low + high) / 2;
            if(check(graph, mid, k)){
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};