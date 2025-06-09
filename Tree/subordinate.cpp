
// T.c ->  O(n node + n-1 edges) = O(n) 💯💯

void dfs(vll &ans,vector<int>*adj,int node,int par)
{
   for(auto neib:adj[node])
    {
        if(neib!=par)
        {
            dfs(ans,adj,neib,node);
            ans[node] += ans[neib]+1;
        }
    }
    return;
}

 
