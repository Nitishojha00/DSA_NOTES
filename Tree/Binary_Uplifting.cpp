
// step 1 --->   Create Adjacency List
// step 2 --->   Requirement ---
//             1. LCA 2d vector of size n*(log2(n)+1) , initialize with -1
//             2. Depth vector that store depth of every node


// step 3 ---> Simple DFS to set first parent and depth -> depth[node] = depth[parent]+1  💯

// step 4 ---> Filling all values in lca vector  -> (Dynamic Programming)
//                                             if (lca[i][j - 1] != -1)
//                                                      lca[i][j] = lca[lca[i][j - 1]][j - 1];
                        
// step 5 ----> Handling Query call goes to findLca function

// step 6 ----> firstly if their level not same we bring them at same level

//                                             while(diff>0)
//                                                 {
//                                                     int i = log2(diff);
//                                                     b = lca[b][i];
//                                                     diff-=(1<<i);
//                                                 }
                                                
//                                               //  both values are equal means ancestor found

// step 7 ---->   // Move both a and b up together
//             for (int i = LOG - 1; i >= 0; i--) 
//             {
//                 if (lca[a][i] != lca[b][i]) // beacuse may be  ancestor ka bhi upar ka miljai to 
//                 {
//                     a = lca[a][i];
//                     b = lca[b][i];
//                 }
//             }                                          


#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int n = 7;
const int LOG = 3; // log2(7) ≈ 2.8 → so we take 3

vector<int>adj[n];
vector<vector<int>> lca(n, vector<int>(LOG, -1));
vector<int> depth(n);

   // dfs is used to set just parent of every node and setting depth on node 💯 easy
   void dfs(int node, int parent)
    {
        lca[node][0] = parent;  // setting first parent
        if (parent != -1)  // depth from root node set krrha
            depth[node] = depth[parent] + 1;

        for (int child : adj[node]) 
        {
            if (child != parent)
                dfs(child, node);
        }
    }

    // kabhi bhi isko banana ho to example lelo and dry run krke banalo 
    void buildLCA() 
    {
        for (int j = 1; j < LOG; j++) 
        {
            for (int i = 0; i < n; i++) 
            {
                if (lca[i][j - 1] != -1)
                    lca[i][j] = lca[lca[i][j - 1]][j - 1];
            }
        }
    }

    // LCA query between a and b
    int findLCA(int a, int b)  // initially a==b then also it handle
    {
        if (depth[a] > depth[b])
            swap(a, b);

        int diff = depth[b] - depth[a];

        // Bring a up to the same level as b
        while(diff>0)
        {
            int i = log2(diff);
            b = lca[b][i];
            diff-=(1<<i);
        }

        if (a == b) return a;

        // Move both a and b up together
        for (int i = LOG - 1; i >= 0; i--) 
        {
            if (lca[a][i] != lca[b][i]) 
            {
                a = lca[a][i];
                b = lca[b][i];
            }
        }

        // return direct parent
        return lca[a][0];
    }

    void solve() 
    {
        cout << "LCA of 3 and 6 = " << findLCA(3, 6) << "\n"; // 3
        cout << "LCA of 4 and 6 = " << findLCA(4, 6) << "\n"; // 1
        cout << "LCA of 5 and 6 = " << findLCA(5, 6) << "\n"; // 3
    }

    int main() 
    {
        FAST_IO;

        vector<pair<int,int>> edges = {  {0, 1}, {0, 2}, {1, 3}, {1, 4}, {3, 5}, {3, 6} };
        // created adjoint vector
        for (auto [u, v] : edges) 
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0, -1);     // Step 1: DFS to fill depth[] and lca[node][0]
        buildLCA();     // Step 2: Binary lifting (DP) filling lca[node][j] DP repeting topic mst hai
        solve();        // Step 3: Query Solving

        return 0;
    }
