//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxlen=0;
    int solve(int i, int j, int n, int m, string &s1, string &s2, vector<vector<int>> &dp){
        if(i>=n || j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]){
          dp[i][j]=1+solve(i+1,j+1,n,m,s1,s2,dp);
        }
        else dp[i][j]=0;
        
        maxlen=max(maxlen,dp[i][j]);
        return dp[i][j];
    }
    int longestCommonSubstr(string s1, string s2) {
        // your code here
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                solve(i,j,n,m,s1,s2,dp);
            }
        }
        return maxlen;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends