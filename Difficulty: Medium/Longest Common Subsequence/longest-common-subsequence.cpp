//{ Driver Code Starts
#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;


// } Driver Code Ends
// function to find longest common subsequence

class Solution {
  public:
    // Function to find the length of longest common subsequence in two strings.
    int solve(int i, int j, int n, int m, string &str1, string &str2,vector<vector<int>> &dp){
        if(i>=n || j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int maxi=0;

        if(str1[i]==str2[j]){
            maxi=max(maxi,1+solve(i+1,j+1,n,m,str1,str2,dp));
        }
        else{
            int ctr1=solve(i+1,j,n,m,str1,str2,dp);
            int ctr2=solve(i,j+1,n,m,str1,str2,dp);
            maxi=max(maxi,max(ctr1,ctr2));
        }
        
        return dp[i][j]=maxi;
    }
    int lcs(int n, int m, string str1, string str2) {
        // your code here
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(0,0,n,m,str1,str2,dp);
    }
};


//{ Driver Code Starts.
int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m; // Take size of both the strings as input
        string str1, str2;
        cin >> str1 >> str2; // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, str1, str2) << endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends