vector<vector<int>> memo;

int solve(int i, int k, const vector<int>& nums) {
        
      // Base condition 
      // just think whats the last window do it has to cover complete array

        if (memo[i][k] != -1) return memo[i][k];

       // maybe some variable according to question

        for (int j = i; j < n - (k - 1); ++j) { // ensure at least (k-1) elements remain
           // perform operation on current element
            int next = solve(j + 1, k - 1, nums); // calling for next possible window
            // updating the result may come from many time it return 
            // what you have to return from here update that  
               update_return compare with result that comes 
        }

        return memo[i][k] = update_return; // simple store and return 
    }