class Solution {
public:
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (k > n) return -1; // Not enough books

        // we  have to give minimum 1 book thats why -> any student surely get
        //  the book with maximum pages
        int s = *max_element(arr.begin(), arr.end()); 
        int e = accumulate(arr.begin(), arr.end(), 0);
        int ans = INT_MAX;

        while (s <= e) 
        {
            int mid = s + (e - s) / 2;
            int noOfStud = 1;
            int pagesAlloc = 0;

            for (int i = 0; i < n; i++) 
            {
                if (pagesAlloc + arr[i] > mid) 
                {
                    noOfStud++;
                    pagesAlloc = arr[i];
                } 
                else 
                    pagesAlloc += arr[i];
            }

            if (noOfStud > k) // book allocated to more than k student
                s = mid + 1;
            else 
            {
                ans = mid;
                e = mid - 1;
            }
        }

        return ans;
    }
};
