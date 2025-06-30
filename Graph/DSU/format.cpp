  int pathcompression(int node , vector<int>&par)// ye parent bhejta hailekin isme algorithm path compression ki lgti hai jo ki bhut important hai
    {
        if(par[node]!=node)
        return par[node] = pathcompression(par[node],par);
        
        return node;
    }
    
    // pu and pv is parent of node u and v respectively
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