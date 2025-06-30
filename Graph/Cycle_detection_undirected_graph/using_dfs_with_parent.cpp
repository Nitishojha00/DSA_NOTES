// joing simple traversal with parent check
// if the the node is visited and it is 
// not the parent of the current node then cycle is present

class Solution {
  public:
  
    bool dfs(int node  , int par , vector<int>adj[] , vector<bool>&vis)
    {
        vis[node] = 1;
        bool ans = 0;
        for(auto neib:adj[node])
        {
            if(neib==par) continue;
            
            if(vis[neib]) return true;
            
            ans = ans|dfs(neib,node,adj,vis);
        }
        
        return ans;
    }
  
    bool isCycle(int n, vector<vector<int>>& edges) {
        // Code here
        // simple dfs krunga path me pada hua firse node visit hua parent kko chodke mtlb cycle hai
        
        // making the adjacency vector
        vector<int>adj[n];
        for(auto e:edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<bool>vis(n);
        for(int i=0;i<n;i++)
        {
            if(!vis[i] && dfs(i,-1,adj,vis))
            {
              return  1;
            }
        }
        
        return 0;
    }
};