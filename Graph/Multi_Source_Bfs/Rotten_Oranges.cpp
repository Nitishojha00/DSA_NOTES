class Solution {
public:
int r[5] = {1,0,-1,0,1};

    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,pair<int,int>>>q;
        int cnt = 0;  
        // we count how much not unrotten oranges ans pushing rotten oranges in queue
        // so that we can do multi source bfs
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                q.push({0,{i,j}});

                if(grid[i][j]==1)
                 cnt++;
            }
        }
        //cout<<q.front().second.first<<endl;
        int ans = 0,count = 0;
        while(!q.empty())
        {
             int t = q.front().first;
             int x = q.front().second.first;
             int y = q.front().second.second;
             q.pop();
             for(int i=0;i<4;i++)
             {
                int nx = x+r[i];
                int ny = y+r[i+1];
                if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1)
                {
                    count++;
                    grid[nx][ny] = 2;
                    ans = max(ans,t+1);
                    q.push({t+1,{nx,ny}});
                }
             }
        }
        
        return count<cnt?-1:ans;

    }
};