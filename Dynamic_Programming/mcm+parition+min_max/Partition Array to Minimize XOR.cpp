class Solution {
public:
    int n;
    vector<vector<int>> memo;
    
    int solve(int i, int k, const vector<int>& nums) {
        if (k == 1) {
            int xorVal = 0;
            for (int j = i; j < n; ++j) xorVal ^= nums[j];
            return xorVal;
        }

        if (memo[i][k] != -1) return memo[i][k];

        int minMaxXor = INT_MAX;
        int xorNow = 0;

        for (int j = i; j < n - (k - 1); ++j) { // ensure at least (k-1) elements remain
            xorNow ^= nums[j];
            int next = solve(j + 1, k - 1, nums);
            int curMax = max(xorNow, next);
            minMaxXor = min(minMaxXor, curMax);
        }

        return memo[i][k] = minMaxXor;
    }

    
    int minXor(vector<int>& nums, int k) {
         n = nums.size();
         
        memo.assign(n + 1, vector<int>(k + 1, -1));
        return solve(0, k, nums);
    }
};