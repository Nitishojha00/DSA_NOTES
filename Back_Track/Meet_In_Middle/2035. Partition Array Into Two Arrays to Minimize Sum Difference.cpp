//You are given an integer array nums of 2 * n integers. 
// You need to partition nums into two arrays of length n 
// to minimize the absolute difference of the sums of the arrays. 
// To partition nums, put each element of nums into one of the two arrays.

//Return the minimum possible absolute difference.

//constraint -> n <= 15 ,  array size = 2*n   by constraints samjh gaya

class Solution {
public:
    void find(vector<int>& nums, int n, int s, vector<int> v[], int sum, int cnt) { // finding all the way
        if (n < s) {
            v[cnt].push_back(sum);
            return;
        }
        find(nums, n - 1, s, v, sum, cnt);               // Exclude
        find(nums, n - 1, s, v, sum + nums[n], cnt + 1); // Include
    }

    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int n_ = n / 2;
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // Edge case for n == 2
        if (n == 2) return abs(nums[0] - nums[1]);

        vector<int> v1[16], v2[16];

        // Generate subset sums for both halves
        find(nums, n_ - 1, 0, v1, 0, 0);
        find(nums, n - 1, n_, v2, 0, 0);

        // Sort all v2[i] to enable binary search
        for (int i = 0; i <= n_; i++) {
            sort(v2[i].begin(), v2[i].end());
        }

        int ans = INT_MAX;

        // Meet-in-the-middle approach
        for (int i = 0; i <= n_; i++) {
            for (int val1 : v1[i]) {
                int val2 = totalSum / 2 - val1; // Ideal balance value
                int sizeNeeded = n_ - i;

                auto x = lower_bound(v2[sizeNeeded].begin(), v2[sizeNeeded].end(), val2);
                
                // Check both x and x-1 for minimum difference
                if (x != v2[sizeNeeded].end()) {
                    int val11 = *x;
                    int sum1 = val1 + val11;
                    int sum2 = totalSum - sum1;
                    ans = min(ans, abs(sum1 - sum2));
                }
                if (x != v2[sizeNeeded].begin()) {
                    --x;
                    int val11 = *x;
                    int sum1 = val1 + val11;
                    int sum2 = totalSum - sum1;
                    ans = min(ans, abs(sum1 - sum2));
                }
            }
        }
        return ans;
    }
};
