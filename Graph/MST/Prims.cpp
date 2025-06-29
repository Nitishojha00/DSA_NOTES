class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	typedef pair<int,pair<int,int>>p;
    int spanningTree(int V, vector<vector<int>> adj[])//its represention array of 2d vector
    {
        // code here
       // adj[i][j][0] representing the node that connnected to that particular node
       //adj[i][j][1] its reprsenting the weight
       priority_queue<p, vector<p> , greater<p>>pq;
       pq.push({0,{0,-1}});
       vector<int>parent(V,0);
       vector<bool>isMST(V,0);
       int cost  = 0;
       while(!pq.empty())
       {
           int wt = pq.top().first;
           int node = pq.top().second.first;
           int par_node = pq.top().second.second;
           pq.pop();
           if(!isMST[node])
           {
               isMST[node] = 1;
               cost+=wt;
                parent[node] = par_node;
               for(int j=0;j<adj[node].size();j++)
               {
                   if(!isMST[adj[node][j][0]])
                   pq.push({adj[node][j][1],{adj[node][j][0],node}});
               }
           }
           
       }
       return cost;
    }
};