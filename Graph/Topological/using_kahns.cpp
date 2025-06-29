class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
         vector<int>v(V,0);
        queue<int>q;
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                v[adj[i][j]]++;
            }
        }
        for(int i=0;i<V;i++)
        if(!v[i])
        q.push(i);
        vector<int>ans;
        while(!q.empty())
        {
            int node = q.front();
            ans.push_back(node);
            q.pop();
            int i=0;
            while(i<adj[node].size())
            {
                v[adj[node][i]]--;
                if(!v[adj[node][i]])
                q.push(adj[node][i]);
                i++;
            }
        }
        return ans;
	}
};