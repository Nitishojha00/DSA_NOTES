#include <bits/stdc++.h>
using namespace std;

vector<int> stree;
vector<int>lazy;
int n;

void BuildStree(int ind, int ss, int se, vector<int> &nums) 
{
    if (ss == se) 
    {
        stree[ind] = nums[ss];
        return;
    }

    int mid = ss + (se - ss) / 2;
    BuildStree(2 * ind + 1, ss, mid, nums);
    BuildStree(2 * ind + 2, mid + 1, se, nums);
    stree[ind] = stree[2 * ind + 1] + stree[2 * ind + 2];
}

void Range_Update(int ss, int se,int rs, int re,  int val, int ind) 
{
    if(lazy[ind]!=0)
    {
         int v = lazy[ind];
         lazy[ind] = 0;
         stree[ind]+=((se-ss+1)*v);
         if(ss!=se)
         {
            lazy[2*ind+1] += v;
            lazy[2*ind+2] += v;
         }
    }

       if (re < ss || rs > se) return ; // No overlap
  
        if (rs <= ss && se <= re)  // Total overlap
        {
            stree[ind] += ((se-ss+1)*val);
             if(ss!=se)
              {
                 lazy[2*ind+1] += val;
                 lazy[2*ind+2] += val;
              }
              return;
        }
        
        int mid = ss + (se - ss) / 2;
        Range_Update(ss, mid, rs, re , val , 2 * ind + 1) ;
        Range_Update(mid + 1, se, rs, re , val , 2 * ind + 2);

        stree[ind] = stree[2 * ind + 1] + stree[2 * ind + 2];
}

int RangeSum(int ss, int se, int rs, int re, int ind)
{
    if(lazy[ind]!=0)
    {
         int val = lazy[ind];
         lazy[ind] = 0;
         stree[ind]+=((se-ss+1)*val);
         if(ss!=se)
         {
            lazy[2*ind+1] += val;
            lazy[2*ind+2] += val;
         }
    }

    if (re < ss || rs > se) return 0; // No overlap

    if (rs <= ss && se <= re) return stree[ind]; // Total overlap

    int mid = ss + (se - ss) / 2;
    return RangeSum(ss, mid, rs, re, 2 * ind + 1) +
           RangeSum(mid + 1, se, rs, re, 2 * ind + 2);
}

void solve(vector<int> &nums)
{
    n = nums.size();
    stree.resize(4 * n);
    lazy.resize(4 * n);
    BuildStree(0, 0, n - 1, nums);
}

int main() 
{
    vector<int> nums = {1, 3, 5, 7, 9};  // Initial array
    solve(nums);  // Build segment tree

    // Initial sum query from index 1 to 3 (3 + 5 + 7 = 15)
    cout << "Sum from index 1 to 3: " << RangeSum(0, n - 1, 1, 3, 0) << endl;

    // Range update: add 10 to elements from index 1 to 3
    Range_Update(0, n - 1, 1, 3, 10, 0);

    // After update: (3+10) + (5+10) + (7+10) = 13 + 15 + 17 = 45
    cout << "After update, sum from index 1 to 3: " << RangeSum(0, n - 1, 1, 3, 0) << endl;

    // Sum from index 0 to 4: (1) + (13) + (15) + (17) + (9) = 55
    cout << "Sum from index 0 to 4: " << RangeSum(0, n - 1, 0, 4, 0) << endl;

    return 0;
}
