//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int mod=1e9+7;
    int solve(int x, int y, vector<vector<int>> &dp){
        if(x<=0 && y<=0) return 1;
        if(dp[x][y]!=-1) return dp[x][y];
        
        int ways=0;
        
        if(x>0) ways+=(solve(x-1,y,dp))%mod;
        if(y>0) ways+=(solve(x,y-1,dp))%mod;
        
        return dp[x][y]=ways%mod;
    }
    int ways(int x, int y)
    {
        //code here.
        vector<vector<int>> dp(x+1,vector<int> (y+1,-1));
        return solve(x,y,dp);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<<ob.ways(x,y)<<endl;
    }
	return 0;
}

// } Driver Code Ends