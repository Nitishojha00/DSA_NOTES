
class Solution {
  public:


    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int>adj[V];
        for(auto e:edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i])
            {
                queue<pair<int,int>>q;
                visited[i] == true;
                q.push({i,-1});
                while(!q.empty())
                {
                    int node  = q.front().first;
                    int par = q.front().second;
                    q.pop();
                    
                    for(auto neib:adj[node])
                    {
                        if(neib==par) continue;
                        
                        if(visited[neib])  return true;
                        
                        visited[neib] = true;
                        q.push({neib,node});
                    }
                }
            }
        }
        return false;
    }
};