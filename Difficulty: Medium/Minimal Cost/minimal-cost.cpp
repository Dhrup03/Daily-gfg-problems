//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int minimizeCost(int k, vector<int>& arr) 
    {
        int n=arr.size();
        vector<int>mini(n,INT_MAX);
        mini[n-1]=0;
        for(int i=n-2;i>=0;i--)
        {
            int mi=INT_MAX;
            for(int j=0;j<k;j++)
            {
                if(i+j+1<n)
                {
                    int cost=abs(arr[i]-arr[i+j+1])+mini[i+j+1];
                    mi=min(mi,cost);
                }
            }
            mini[i]=mi;
        }
        return mini[0];
    }

};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends