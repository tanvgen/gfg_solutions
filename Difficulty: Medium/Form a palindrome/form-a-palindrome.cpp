//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
  
    int solve(int i, int j, string &str, string &s, vector<vector<int>> &dp, int n){
        // int n=str.size();
        // int m=s.size();
        if(str==s) return n;
        if(i>=n || j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int len=0;
        if(str[i]==s[j]){
            len+=(1+solve(i+1,j+1,str,s,dp,n));
        }
        else{
            len+=max(solve(i+1,j,str,s,dp,n),solve(i,j+1,str,s,dp,n));
        }
        
        return dp[i][j]=len;
        
    }
    int countMin(string str){
    //complete the function here
        string s=str;
        reverse(s.begin(),s.end());
        int n=str.size();
        
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int ans=solve(0,0,str,s,dp,n);
        
        return n-ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends