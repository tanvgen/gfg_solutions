//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  int n;
    bool solve(int i, int j, vector<int> &arr, int sum, vector<vector<int>> &dp){
        if(i==n){
            if(j==sum) return 1;
            else return 0;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int take=0;
        if(j+arr[i]<=sum) take=solve(i+1,j+arr[i],arr,sum,dp);
        
        int ntake=solve(i+1,j,arr,sum,dp);
        
        return dp[i][j]=take||ntake;
    }
    bool isSubsetSum(vector<int> arr, int sum) {
        // code here
        n=arr.size();
        vector<vector<int>> dp(n,vector<int> (sum+1,-1));
        
        return solve(0,0,arr,sum,dp);
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
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}

// } Driver Code Ends