
// T.c ->  O(n node + n-1 edges) = O(n) 💯💯
// kitna log mere andar kam krrha 1-2-3-4-5
//  1 leader haito uske andar 4 kam krrha , 2 ke andar 3 kam krrha , 3 ke andar 2 kam krrha , 4 ke andar 1 kam krrha wo 5
// simple ans vector initilaised with 0 while return from any node ans[node] = ans[neib]+1; 1 is for neighbour simple 

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

 
