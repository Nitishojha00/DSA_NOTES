class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void dfs(int node , vector<int>&v,stack<int>&st, vector<int>adj[])
	{
	    v[node] = 1;
	    for(int i=0;i<adj[node].size();i++)
	    if(v[adj[node][i]]==-1)
	    dfs(adj[node][i],v,st,adj);
	    st.push(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
          stack<int>st;
          vector<int>v(V,-1);
          for(int i=0;i<V;i++)
          if(v[i]==-1)
          dfs(i,v,st,adj);
          vector<int>ans;
          while(!st.empty())
          {
          ans.push_back(st.top());
          st.pop();
          }
          return ans;
	}
};