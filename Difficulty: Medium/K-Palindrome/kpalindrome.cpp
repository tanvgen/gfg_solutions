//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i, int j, string &str, string &s, int n, vector<vector<int>> &dp){
        if(i>=n || j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int len=0;
        if(str[i]==s[j]){
            len=1+solve(i+1,j+1,str,s,n,dp);
        }
        else{
            len=max(solve(i,j+1,str,s,n,dp), solve(i+1,j,str,s,n,dp));
        }
        
        return dp[i][j]=len;
    }
    int kPalindrome(string str, int n, int k)
    {
        // code here
        string s=str;
        reverse(s.begin(),s.end());
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int ctr=solve(0,0,str,s,n,dp);
        
        if(n-ctr<=k) return 1;
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.kPalindrome(str, n, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends