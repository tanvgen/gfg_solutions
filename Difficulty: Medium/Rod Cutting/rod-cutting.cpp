//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int solve(int i, int j, int price[], int n, int len[], vector<vector<int>> &dp){
        if(i>=n || j>n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int take=0;
        if(len[i]+j<=n){
            take=price[i]+solve(i,j+len[i],price,n,len,dp);
        }
        int ntake=solve(i+1,j,price,n,len,dp);
        
        return dp[i][j]=max(ntake,take);
    }
    
    int cutRod(int price[], int n) {
        //code here
        int len[n];
        for(int i=0; i<n; i++){
            len[i]=i+1;
        }
        
        vector<vector<int>> dp(n,vector<int> (n+1,-1));
        
        return solve(0,0,price,n,len,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends