//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i, int j, int N, int W, int val[], int wt[], vector<vector<int>> &dp){
        // if(i==N){
        //     if(j==W) return dp[i][j];
        //     else return 0;
        // }
        if(i>=N || j>W) return 0;
        //if(j>W) return dp[i][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int take=0;
        if(j+wt[i]<=W) take=val[i]+solve(i,j+wt[i],N,W,val,wt,dp);
        int ntake=solve(i+1,j,N,W,val,wt,dp);
        
        return dp[i][j]=max(take,ntake);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N,vector<int> (W+1,-1));
        return solve(0,0,N,W,val,wt,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends