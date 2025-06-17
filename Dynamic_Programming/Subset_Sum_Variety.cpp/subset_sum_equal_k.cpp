// top down and recursion + memoization 

class Solution {
  public:
   vector<vector<int>>dp;
//   bool solve(vector<int>&arr , int sum , int n)
//   {
//       if(sum==0)  return 1;
      
//       if(n<=0)  return 0;
      
//       if(dp[n][sum]!=-1) return dp[n][sum];
      
      
//       if(arr[n-1]<=sum)
//       {
//           return dp[n][sum] =  solve(arr,sum-arr[n-1],n-1) || solve(arr,sum,n-1);
//       }
//       else
//       {
//           return dp[n][sum] =  solve(arr,sum,n-1);
//       }
//   }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        dp.resize(n+1,vector<int>(sum+1,0));
        
        // initialization according to base condition
        for(int i=0;i<=n;i++)
            dp[i][0] = 1;
       
       for(int i=1;i<=n;i++)
       {
          for(int j=1;j<=sum;j++)
          {
              if(j>=arr[i-1])
              {
                  dp[i][j] = dp[i-1][j]||dp[i-1][j-arr[i-1]];
              }
              else
              {
                  dp[i][j] = dp[i-1][j];
              }
          }
       }
       
       return dp[n][sum];
    }
};