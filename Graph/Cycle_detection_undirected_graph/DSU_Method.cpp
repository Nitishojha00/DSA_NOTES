// logic kya hoga using dsu
// use union find when edge list given

//💲💲💲 Important Point 

// ✅ Use Union-Find:

// If graph is in edge list form

// When checking connectivity as you add edges

// In MST or dynamic connectivity problems

// If you want fast cycle check without full traversal

// ✅ Use BFS:

// If you already have adjacency list

// If you want to record or reconstruct the cycle path

// If you're solving graph traversal-based problems

class Solution {
  public:
      vector<int> parent, rank;

    int find(int x) {
        if(parent[x] == x)  return x;  // if self parent then return itself

        return parent[x] = find(parent[x]);  // path compression
    }

    bool unionSet(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if(pu == pv) return false;  // cycle detected

        // union by rank
        if(rank[pu] < rank[pv]) parent[pu] = pv;
        else if(rank[pu] > rank[pv]) parent[pv] = pu;
        else 
        {
            parent[pu] = pv;
            rank[pv]++;
        }
        return true;
    }

    bool isCycle(int n, vector<vector<int>>& edges) {

        parent.resize(n);
        rank.resize(n, 0);
        // initializing self parent of each node to itself
        for(int i = 0; i < n; i++) parent[i] = i;
        
        // iterating through all edges
        // and applying union find
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            if (!unionSet(u, v)) {
                return true;  // cycle found
            }
        }

        return false;
    }
};
