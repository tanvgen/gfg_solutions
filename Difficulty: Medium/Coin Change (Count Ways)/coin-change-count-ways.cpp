//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long solve(int i, int j, int n, vector<int> &coins, int sum, vector<vector<long long>> &dp){
        if(i==n){
            if(j==sum) return 1;
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        
        long long take=0;
        if(j+coins[i]<=sum){
            take=solve(i,j+coins[i],n,coins,sum,dp);
        }
        long long ntake=solve(i+1,j,n,coins,sum,dp);
        
        return dp[i][j]=take+ntake;
    }
    long long int count(vector<int> coins, int sum) {
        // code here.
        int n=coins.size();
        vector<vector<long long>> dp(n,vector<long long>(sum+1,-1));
        return solve(0,0,n,coins,sum,dp);
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
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends