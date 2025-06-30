bool isCyclic(int V, vector<int> adj[]) {
    vector<int> inDegree(V, 0);

    // Count incoming edges for each node
    for (int i = 0; i < V; i++) {
        for (int x : adj[i]) {
            inDegree[x]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0)
            q.push(i);
    }

    int count = 0;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        count++;
        for (int x : adj[node]) {
            if (--inDegree[x] == 0)
                q.push(x);
        }
    }

    return count != V;  // if not all nodes are processed → cycle
}
