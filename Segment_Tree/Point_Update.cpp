#include <bits/stdc++.h>
using namespace std;

vector<int> stree;
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

void Point_Update(int ss, int se, int target_index, int val, int ind) 
{
    if (ss == se) 
    {
        stree[ind] = val;
        return;
    }

    int mid = ss + (se - ss) / 2;
    if (target_index <= mid)
        Point_Update(ss, mid, target_index, val, 2 * ind + 1);
    else
        Point_Update(mid + 1, se, target_index, val, 2 * ind + 2);

    stree[ind] = stree[2 * ind + 1] + stree[2 * ind + 2];
}

int RangeSum(int ss, int se, int rs, int re, int ind)
{
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
    BuildStree(0, 0, n - 1, nums);
}

int main() 
{
    vector<int> nums = {1, 3, 5, 7, 9};
    solve(nums);

    cout << "Sum from index 1 to 3: " << RangeSum(0, n - 1, 1, 3, 0) << endl; // 3 + 5 + 7 = 15

    Point_Update(0, n - 1, 2, 10, 0); // Update index 2 to 10

    cout << "After update, sum from index 1 to 3: " << RangeSum(0, n - 1, 1, 3, 0) << endl; // 3 + 10 + 7 = 20

    return 0;
}
