class Solution {
public:
    typedef pair<int,pair<int,int>> p;
       
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        set<p>s;
        //making adjoint vector
          vector<pair<int,int>>adj[n];
          for(auto i:flights)
          {
            adj[i[0]].push_back({i[1],i[2]});
          }
        
        int ans  = INT_MAX;
        s.insert({0,{0,src}});
        while(s.size()>0)
        {
          
            int price =  (*s.begin()).first;
              auto pair  =   (*s.begin()).second;
              int count = pair.first;
              int node = pair.second;
            if(node == dst)
                return price;
              s.erase(s.begin());
                for(auto it:adj[node])
                {
                     auto newprice = it.second;
                     auto newnode = it.first;
                    if(count<=k)
                    s.insert({price+newprice,{count+1,newnode}});
                }
         }
           
    //    int ans = INT_MAX;
       return -1;
     
    }
};

































