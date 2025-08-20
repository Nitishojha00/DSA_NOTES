#include<bits/stdc++.h>
using namespace std;
 void heapify(int i,int n, vector<int>&nums)
    {
        int i1 = 2*i+1;
        int i2 = 2*i+2;
        int idx = i , val = nums[i];
        if(i1<n  && val<nums[i1])
        {
            val = nums[i1];
            idx = i1;
        }

        if(i2<n && val<nums[i2])
        {
            val = nums[i2];
            idx = i2;
        }

        if(idx!=i)
        {
            swap(nums[i],nums[idx]);
            heapify(idx,n,nums);
        }
        return;
    }
    void heapSort(vector<int>&nums)
    {
        int n = nums.size();
        for(int i = n/2 - 1; i >= 0; i--) {
            heapify(i, n, nums);
        }


        for(int i=n-1;i>=0;i--)
        {
            swap(nums[0],nums[i]);
            heapify(0,i,nums);
       }
       return ;
    }
    int main() {
        vector<int> nums;
        nums.push_back(1);
        nums.push_back(2);
        nums.push_back(3);
        nums.push_back(4);
        nums.push_back(5);
        nums.push_back(6);

        heapSort(nums);
        for(auto val:nums)
        {
            cout<<val<<" ";
        }
        return 0;
    }
