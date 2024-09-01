//{ Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int mod=1e9+7;
    int solve(int i, int n, int x, vector<vector<int>> &dp){
        if(n<0) return 0;
        if(n==0) return 1;
        if(pow(i,x)>n) return 0;
        
        if(dp[n][i]!=-1) return dp[n][i];
        int temp=pow(i,x);
        
        int way1=solve(i+1,n-temp,x,dp)%mod;
        int way2=solve(i+1,n,x,dp)%mod;
        
        return dp[n][i]=(way1+way2)%mod;
    }
    int numOfWays(int n, int x)
    {
        // code here
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return solve(1,n,x,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}

// } Driver Code Ends