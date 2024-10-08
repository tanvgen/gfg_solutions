//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    long long int const mod = 1000000007;
    long long solve(int i, int j, string &str, vector<vector<long long>> &dp){
        if(i>j) return 0;
        if(i==j) return dp[i][j]=1;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(str[i]==str[j]){
            return dp[i][j]=(1+solve(i+1,j,str,dp)+solve(i,j-1,str,dp))%mod;
        }
        else{
            return dp[i][j]=(solve(i+1,j,str,dp)+solve(i,j-1,str,dp)-solve(i+1,j-1,str,dp)+mod)%mod;
        }
    }
    long long int  countPS(string str)
    {
       //Your code here
       int n=str.size();
       vector<vector<long long>> dp(n,vector<long long>(n,-1));
       return solve(0,n-1,str,dp);
    }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends