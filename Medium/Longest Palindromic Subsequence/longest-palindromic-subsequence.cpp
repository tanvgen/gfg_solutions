//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string A) {
        //code here
        string B= A;
        reverse(B.begin(), B.end());
        //cout<<B;
        int n=A.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1,-1));
        for(int i=0; i<=n; i++){
            dp[i][0]=0;
            dp[0][i]=0;
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(A[i-1]==B[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends