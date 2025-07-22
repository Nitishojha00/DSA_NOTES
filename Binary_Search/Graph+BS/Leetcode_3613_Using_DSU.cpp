// 3613. Minimize Maximum Component Cost

// You are given an undirected connected graph with n nodes labeled from 0 to n - 1 and a 2D
//  integer array edges where edges[i] = [ui, vi, wi] denotes an undirected edge between 
//  node ui and node vi with weight wi, and an integer k.

// You are allowed to remove any number of edges from the graph such that the 
// resulting graph has at most k connected components.

// The cost of a component is defined as the maximum edge weight in that component.
//  If a component has no edges, its cost is 0.

// Return the minimum possible value of the maximum cost among all components after such removals.

class Solution {
public:
    vector<int> par, rank;
 int findPar(int u)
 {
    if(u==par[u]) return u;

    return par[u] = findPar(par[u]);
 }
 void unionOfRank(int u,int v)
 {
    int pu = findPar(u);
    int pv = findPar(v);
    if(pu==pv) return;
    if(pu!=pv)
    {
        if(rank[pu]>rank[pv])
        {
             par[pv] = pu;
        }
        else if(rank[pv]>rank[pu])
        {
             par[pu] = pv;
        }
        else
        {
            rank[pu] += 1;
            par[pv] = pu;
        }
    }
 }
bool check(vector<vector<int>>& edges, int weightLimit, int maxComponents, int n)
{
    par.assign(n, 0);
    rank.assign(n, 0);

    for(int i = 0; i < n; i++)
        par[i] = i;
    
    for(auto& e : edges)
    {
        int u = e[0], v = e[1], w = e[2];
        if(w <= weightLimit)
        {
            unionOfRank(u, v);
        }
    }

    unordered_set<int> Unique_Par;
    for(int i = 0; i < n; i++)
        Unique_Par.insert(findPar(i));

    return Unique_Par.size() <= maxComponents;  // ✅ correct condition
}

 int minCost(int n, vector<vector<int>>& edges, int k) 
   {
        if (n == 0) return 0;
        if (edges.empty()) return (n <= k) ? 0 : -1;

        int low = 0, high = 0, ans = -1;

        for (auto& edge : edges)
            high = max(high, edge[2]);

        while(high>=low)
        {
            int mid = low+(high-low)/2;
            if(check(edges,mid,k,n))
            {
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }

      return ans;
    }
};