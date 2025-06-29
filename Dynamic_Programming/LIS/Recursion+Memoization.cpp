class Solution {
public:
   int lds(vector<int>&nums, int mx , int n)
   {
        if(n<0)  return 0;

        int ans = 0;
        if(nums[n]<mx)
         ans = 1+lds(nums,nums[n],n-1);

        return max(ans,lds(nums,mx,n-1));
   }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
         return lds(nums,INT_MAX,n-1);
    }
};



// memoization

class Solution {
public:


vector<vector<int>>dp;

    int lds(vector<int>& nums, int prev, int n) 
    {
        if(n<0 || prev<0)  return 0;
        
        if(dp[prev][n]!=-1) return dp[prev][n];

        int ans = 0;
        if(nums[prev]<nums[n])
        {
            ans = 1+lds(nums,prev-1,prev);
        }

         return dp[prev][n] = max(ans,lds(nums,prev-1,n));
    }

    
    int lengthOfLIS(vector<int>& nums) {
        nums.push_back(INT_MAX);
        int n = nums.size();
        dp.resize(n,vector<int>(n,-1));
         return lds(nums,n-2,n-1);
    }
};