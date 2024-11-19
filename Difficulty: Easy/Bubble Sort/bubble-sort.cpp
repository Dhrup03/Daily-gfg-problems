//{ Driver Code Starts
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(vector<int>& arr) {
        // Your code here
        int n = arr.size();
         for (int i = n - 2; i >= 0; i--)
    {
        bool swapped = false; // Initialize swapped to false for each iteration
        for (int j = 0; j <= i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap adjacent elements if they are in the wrong order
                swap(arr[j], arr[j + 1]);
                swapped = true; // Set swapped to true since a swap occurred
            }
        }

        // If no swaps occurred, the array is already sorted
        if (!swapped)
            break;
    
        }
    }
};


//{ Driver Code Starts.

// Driver program to test above functions
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;

        ob.bubbleSort(arr);
        for (int e : arr) {
            cout << e << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends