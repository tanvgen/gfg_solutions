//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    const int mod=1e9+7;
    int solve(int i, int j, int n, int k, vector<int>& A, vector<vector<int>> &dp){
        if(i>=n){
            if(j==k) return 1;
            else return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        
        int take=0;
        if(j+A[i]<=k) take=solve(i+1,j+A[i],n,k,A,dp)%mod;
        int ntake=solve(i+1,j,n,k,A,dp)%mod;
        
        return (take+ntake)%mod;
    }
    long long findTargetSumWays(int n, vector<int>& A, int target) {
        // Your code here
        int  mod=1e9+7;
        int sum=0;
        for(auto it: A){
            sum+=(it);
        }
        int k=target+sum;
        
        if(k<0 || k%2!=0) return 0;
        else{
            k=k/2;
            vector<vector<int>> dp(n,vector<int>(k+1,-1));
            
            return solve(0,0,n,k,A,dp);
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin >> N;
        vector<int> arr(N);

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout << ob.findTargetSumWays(N, arr, target);
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends