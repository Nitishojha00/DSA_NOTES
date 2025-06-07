//  complete code is same linke binary uplifting 
// Maths (logic) ---> dis = depth[u]+depth[v]-2*depth[ancestor]
// Question said that answer[i] is the number of valid assignments for queries[i].

// we can assign 1 or 2 --> where 1 is odd and 2 is even it means we have 2 options
// You are given a 2D integer array queries. For each queries[i] = [ui, vi], determine the number of ways
//  to assign weights to edges in the path such that the cost of the path between ui and vi is odd.
// total 2^n ways and  half of total ways cost of path is odd take example and check
// kitni tarika se 1,2 ko distribut kre ki path sum odd ho total ways/2👌👌👌

class Solution {
public:
using ll = long long;
    int n , maxn;
    vector<vector<int>>adj;
    vector<vector<int>>lca;
    vector<int>depth;
    int power(ll a, ll b, ll mod) 
    { 
        if(b==-1) return 0;
        ll res = 1; 
        while (b > 0) 
        {
            if (b & 1) 
            res = (res * a) % mod; 
            a = (a * a) % mod; b >>= 1;
        } 
          
       return (int)res;
    }

    void dfs(int node, int par)
    {
        lca[node][0] = par;
        if(par!=-1) 
          depth[node] = depth[par]+1;
        
         for(auto neib:adj[node])
           if(neib!=par)
             dfs(neib,node);
    }

    void buildLca()
    {
       for(int j=1;j<maxn;j++)
       {
            for(int i=0;i<n;i++)
            {
                if(lca[i][j-1]!=-1)
                 lca[i][j] = lca[lca[i][j-1]][j-1];
            }
       }
    }

    int findLca(int a , int b)
    {
         if(depth[a]>depth[b]) swap(a,b);

         int diff = depth[b]-depth[a];
         while(diff>0)
         {
            int i = log2(diff);
            b = lca[b][i];
            diff-=(1<<i);
         } // ab level same hogya 

         if(a==b)  return a;

         for(int i=maxn-1;i>=0;i--)
         {
            if(lca[a][i]!=lca[b][i])
            {
                a = lca[a][i];
                b = lca[b][i];
            }
         }

         return lca[a][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& q) {
        n = edges.size()+1;
        maxn = log2(n)+1;
        adj.resize(n);
        lca.resize(n,vector<int>(maxn,-1));
        depth.resize(n);
        for(int i=0;i<n-1;i++)
        {
             int u = edges[i][0];
             int v = edges[i][1];
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        } // created adjacecy vector

        dfs(0,-1);
        buildLca();
        int qs = q.size();
        vector<int>ans(qs);
        for(int i=0;i<qs;i++)
        {
            int u = q[i][0]-1;
            int v = q[i][1]-1;
            int ancestor = findLca(u,v);
            ll d = depth[u] + depth[v] - 2 * depth[ancestor];
            if (d == 0) ans[i] = 0; // means that node self so no way to assign return 0
            else 
            ans[i] = power(2ll, d - 1, 1e9 + 7);
        }
        return ans;
    }
};