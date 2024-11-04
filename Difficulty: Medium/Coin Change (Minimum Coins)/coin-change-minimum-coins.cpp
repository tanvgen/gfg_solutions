//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int solve(int i, int j, int n, vector<int> &coins, int sum, vector<vector<int>> &dp){
        if(i>=n || j>sum) return 1e9;
        if(j==sum) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int take=1e9;
        if(j+coins[i]<=sum){
            take=1+solve(i,j+coins[i],n,coins,sum,dp);    
        }
        
        int ntake=solve(i+1,j,n,coins,sum,dp);
        
        return dp[i][j]=min(take,ntake);
    }
    int minCoins(vector<int> &coins, int sum) {
        // Your code goes here
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        int ans=solve(0,0,n,coins,sum,dp);
        if(ans==1e9) return -1;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int v, m;
        cin >> v >> m;

        vector<int> coins(m);
        for (int i = 0; i < m; i++)
            cin >> coins[i];

        Solution ob;
        cout << ob.minCoins(coins, v) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends