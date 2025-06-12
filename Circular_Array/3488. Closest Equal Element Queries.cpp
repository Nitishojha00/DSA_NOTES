// Store positions of each value in nums:
// Create a map: value → list of indices where it occurs.

// Example: if nums = [1, 2, 1, 3, 1], then positions[1] = [0, 2, 4].

// For each query index:
// Get the value at that index (nums[idx]).
// Get the list of all positions of that value.
// If the value occurs only once → answer is -1.

// Else, find the shortest circular distance:
// Use binary search (lower_bound) to find closest neighbors in the list.

// Compute both:

// Forward circular distance

// Backward circular distance

// Take the minimum of the two.
// Push result to answer list.


            //    ye do line circular array khhatam
           //   int next = inds[(i + 1) % m];
           //  int prev = inds[(i - 1 + m) % m];


vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int sz = nums.size();
        unordered_map<int, vector<int>> positions;

        // Step 1: Collect indices of each value in nums
        for (int i = 0; i < sz; ++i) {
            positions[nums[i]].push_back(i);
        }

        // Step 2: Answer each query directly
        vector<int> res;
        for (int idx : queries) {
            int val = nums[idx];
            const vector<int>& inds = positions[val];

            if (inds.size() == 1) {
                res.push_back(-1); // only one occurrence
                continue;
            }

            // Binary search to find closest indices before and after idx
            auto it = lower_bound(inds.begin(), inds.end(), idx);
            int m = inds.size();
            int i = it - inds.begin();

            // get next and previous positions in circular way
            int next = inds[(i + 1) % m];
            int prev = inds[(i - 1 + m) % m];

            int forward = min(abs(next - idx), sz - abs(next - idx));
            int backward = min(abs(idx - prev), sz - abs(idx - prev));

            res.push_back(min(forward, backward));
        }

        return res;
    }