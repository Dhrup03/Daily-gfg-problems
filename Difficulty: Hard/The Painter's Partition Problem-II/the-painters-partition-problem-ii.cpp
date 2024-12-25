//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minTime(vector<int>& arr, int k) {
        // code here
        // return minimum time
        
        int start = 0 , end = 0 , mid, ans , n = arr.size();
        
        for(int i = 0 ; i<n ; i++){
            start = max(start,arr[i]);
            end += arr[i];
        }
        
        while(start <= end){
            mid = start + (end-start)/2;
            
            int pages = 0 , count = 1;
            
            for(int i = 0; i<n; i++){
                pages += arr[i];
                if(pages > mid){
                    count++;
                    pages = arr[i];
                }
            }
            
            if(count <= k){
                ans = mid;
                end = mid - 1;
            }
            
            else
                start = mid+1;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

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
        int k;
        cin >> k;
        cin.ignore();
        Solution obj;
        cout << obj.minTime(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends