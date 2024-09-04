//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to return maximum sum subarray by removing at most one element.
    int solve(int i, int n, vector<int>& arr, vector<vector<int>>& dp, int deletionspossible){
        if(i>=n) return 0;
        if(deletionspossible<0) return 0;
        if(dp[i][deletionspossible]!=-1) return dp[i][deletionspossible];
        
        //int ntake=INT_MIN;
        int take=arr[i]+solve(i+1,n,arr,dp,deletionspossible);
        int ntake=solve(i+1,n,arr,dp,deletionspossible-1);
        
        return dp[i][deletionspossible]=max(take,ntake);
    }
    int maxSumSubarray(vector<int>& arr) {
        // Your code here
        int n=arr.size();
        int maxi=*max_element(arr.begin(),arr.end());
        if(maxi<0) return maxi;
        
        vector<vector<int>> dp(n,vector<int> (2,-1));
        int deletionspossible=1;
        
        int ans=INT_MIN;
        for(int i=0; i<n; i++){
            ans=max(ans,solve(i,n,arr,dp,deletionspossible));
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.maxSumSubarray(arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends