class Solution {
  public:
    bool dfs(vector<int> adj[], int node, vector<bool>& visited, vector<bool>& recStack) {
        visited[node] = true;
        recStack[node] = true;

        for (auto neib : adj[node]) {
            if (!visited[neib]) {
                if (dfs(adj, neib, visited, recStack))
                    return true;
            } else if (recStack[neib]) {
                return true; // back edge found → cycle
            }
        }

        recStack[node] = false;
        return false;
    }

    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<int> adj[V];
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);  // directed edge
        }

        vector<bool> visited(V, false), recStack(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(adj, i, visited, recStack))
                    return true;
            }
        }

        return false;
    }
};
