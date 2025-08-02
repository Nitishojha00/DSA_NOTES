// Leetcode 3356

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>diff(n+1,0);
        int n1 = queries.size();
        int ptrq = 0;
        int sum = 0;
        int i = 0;
        queries.push_back({0,0,0});
        while(i<=n && ptrq<=n1)
        {
            if(i==n)
             return ptrq;
        
             // without adding queries value already greater 
             if(sum+diff[i]>=nums[i])
             {
                sum+=diff[i];
                i++;
                continue;
             }
            int l = queries[ptrq][0];
            int r = queries[ptrq][1];
            int val = queries[ptrq][2];
            ptrq++;
            if(i>r)
                continue;
              
            if(l>i)
             {
                diff[l]+=val;
                diff[r+1]-=val;
                continue;
             }
             sum+=val;
             diff[r+1] -= val;
             if(sum+diff[i]>=nums[i])
             {
                sum+=diff[i];
                i++;
             }
             else
             {
                continue;
             }

        }

        return -1;
  }
};