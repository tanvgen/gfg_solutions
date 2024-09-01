//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int mod=1e9+7;
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp, int n, int m){
        if(j==m) return 1;
        if(i>=n && j<m) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int way1=0,way2=0;
        if(s1[i]==s2[j]) way1=solve(i+1,j+1,s1,s2,dp,n,m)%mod;
        
        way2=solve(i+1,j,s1,s2,dp,n,m)%mod;
        
        return dp[i][j]=(way1+way2)%mod;
    }
    int countWays(string s1, string s2) {
        // code here
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return solve(0,0,s1,s2,dp,n,m);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}

// } Driver Code Ends