// //
// //  subsetsum1 + (totalsum-subsetsum1) = diff 
// // totalsum and diff given find the subsetsum1 thats the target 
// // now we have to count the number of subset sum equal target
// // condition also change become 0 also possible in array and 0 is their it give 2 option  
//     // if (i == 0) {
//     //     if (sum == 0 && arr[0] == 0) return 2; // pick or not pick zero
//     //     if (sum == 0 || sum == arr[0]) return 1;
//     //     return 0;
//     // }
        


// class Solution {
//   public:
//   vector<vector<int>> dp;
//   const int mod = 1e9 + 7;

//   int solve(vector<int>& arr, int sum, int i) {
//     if (i == 0) {
//         if (sum == 0 && arr[0] == 0) return 2; // pick or not pick zero
//         if (sum == 0 || sum == arr[0]) return 1;
//         return 0;
//     }

//     if (dp[i][sum] != -1) return dp[i][sum];

//     if (arr[i] <= sum)
//         return dp[i][sum] = (solve(arr, sum - arr[i], i - 1) + solve(arr, sum, i - 1)) % mod;
//     else
//         return dp[i][sum] = solve(arr, sum, i - 1);
//   }

//   int countPartitions(vector<int>& arr, int d) {
//       int n = arr.size();
//       int totlsum = accumulate(arr.begin(), arr.end(), 0);

//       if ((totlsum + d) % 2 != 0 || totlsum < d) return 0;

//       int target = (totlsum + d) / 2;
//       dp.resize(n, vector<int>(target + 1, -1));

//       return solve(arr, target, n - 1);
      
//   }
// };

// take example arr = {0} , target = 0  , ans = 2;
// dry run for better understanding why we doing from i = 0;
int countPartitions(int n, int d, vector<int>& arr) {
        int sum=0;
        for(auto i: arr) sum+=i;
        if((d+sum)%2 != 0) return 0;
        int t=(d+sum)/2;
        //REDUCED: find count of subset with sum equal to t
        vector<vector<int>> dp(n+1, vector<int>(t+1, 0));
        dp[0][0] = 1;
        for(int i=1; i<n+1; i++) {
            for(int j=0; j<t+1; j++) {
                if(arr[i-1] <= j) 
                    dp[i][j] = (dp[i-1][j] + dp[i-1][j-arr[i-1]])%1000000007;
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][t];
    }