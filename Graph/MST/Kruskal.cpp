class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    typedef pair<int,pair<int,int>>p;
    
    int pathcompression(int node , vector<int>&par)// ye parent bhejta hailekin isme algorithm path compression ki lgti hai jo ki bhut important hai
    {
        if(par[node]!=node)
        return par[node] = pathcompression(par[node],par);
        
        return node;
    }
    
    void rankfind( int pu , int  pv , vector<int>&rank, vector<int>&par)
    {
        if(rank[pu]>rank[pv])
             par[pv] = pu;
        else if(rank[pv]>rank[pu])
             par[pu] = pv;
        else
           {
               par[pu] = pv;
               rank[pv]++;
           }
        return;
    }
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        //int n = adj.size();
        priority_queue<p , vector<p>, greater<p>>pq;
        for(int i=0;i<V;i++)
        {
            int u = i;
            for(int j=0;j<adj[i].size();j++)
            {
              int v = adj[i][j][0];  
              int dis = adj[i][j][1];  
              pq.push({dis,{u,v}});
            }
        }
        
        int mst = 0;
        vector<bool>v(V,0);
        vector<int>rank(V,0);
        vector<int>par(V,0);
        for(int i=0;i<V;i++)
         par[i] = i;
         
         
        while(!pq.empty())
        {
          int u = pq.top().second.first;
          int dis = pq.top().first;
          int v = pq.top().second.second;
          int pu = pathcompression(u,par);
          int pv = pathcompression(v,par);
          pq.pop();
          if(pu!=pv)
          {
              mst+=dis;
              rankfind(pu,pv,rank,par);
          }
        }
        return mst;
    }
};