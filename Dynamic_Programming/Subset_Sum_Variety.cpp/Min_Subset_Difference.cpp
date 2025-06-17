// subset sum ki variety 
// given a array -> partition that array in two group such that their differece is minimum

class Solution {

  public:
    int minDifference(vector<int>& arr) {
        // Your code goes here
        int sum = 0 , n = arr.size();
        for(int i=0;i<n;i++)  sum+=arr[i];
        

        // subset sum ka code
        vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
        for(int i=0;i<=n;i++)
           dp[i][0] = 1;  // if subset dum equal 0
        for(int i=1;i<=sum;i++)
           dp[0][i] = 0;     // if subset sum greater than 0 and length equal 0
           
           
           for(int i=1;i<=n;i++)
           {
               for(int j=1;j<=sum;j++)
               {
                   if(arr[i-1]<=j)
                   {
                       dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                   }
                   else
                   {
                       dp[i][j] = dp[i-1][j];
                   }
               }
           }
           // last array of dp batati hai ki wo value possible hai
           int ans = INT_MAX;
           for(int i=0;i<=sum;i++)
           {
               if(dp[n][i])
               ans = min(ans,abs(sum-2*(i)));
           }
           return ans;
    }
};
