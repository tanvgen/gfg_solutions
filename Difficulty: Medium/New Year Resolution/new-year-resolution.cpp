//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    
    public:
    int solve(int i, int N , int coins[], vector<vector<int>> &dp, int sum){
        if(sum!=0 && (sum%20==0 || sum%24==0 || sum==2024)){
            return 1;
        }
        
        if(i>=N) return 0;
        
        if(dp[i][sum]!=-1) return dp[i][sum];
        
        bool take=solve(i+1,N,coins,dp,sum+coins[i]);
        bool ntake=solve(i+1,N,coins,dp,sum);
        
        return dp[i][sum]=(take||ntake);
    }
    int isPossible(int N , int coins[]) 
    {
        vector<vector<int>> dp(N,vector<int>(2025,-1)); //2024 is the max sum
        return solve(0,N,coins,dp,0);
    }
    
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int coins[N];
        for(int i=0 ; i<N ; i++)
            cin>>coins[i];

        Solution ob;
        cout << ob.isPossible(N,coins) << endl;
    }
    return 0;
}
// } Driver Code Ends