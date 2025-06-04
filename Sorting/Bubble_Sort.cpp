// stable algo 
// O(n) if already sorted
// T.C. ->  O(n^2)
// worst case arise when array reverse sort 
// inefficient for large data 

//stable algorithm --> If two elements equal then the element which present first before sorting ->  after sorting it always present first 
#include <bits/stdc++.h>
using namespace std;


void bubbleSort(int arr[], int n) 
{
    for (int i = 0; i < n - 1; ++i) 
    {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; ++j) 
        {
            // Swap if current element is greater than next
            if (arr[j] > arr[j + 1]) 
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // Optimization: stop if no swap happened (already sorted)
        if (!swapped)
            break;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    bubbleSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
