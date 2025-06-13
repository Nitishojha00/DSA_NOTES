// upper bound returns a no > xint upper_bound(vector<int> nums, int target)
int upper_bound(vector<int> nums, int target)
{
    int start = 0;
    int end = nums.size()-1;
    int mid = 0;
    while(start<end)
    {
        mid = start  + (end-start)/2;
        if(nums[mid]<=target)    start = mid+1;
        else   end = mid;
    }
    return start;
}