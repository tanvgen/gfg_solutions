//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int solve(int i, int j, int n, string &S, string &str, vector<vector<int>> &dp){
        if(i>=n || j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int len1=0,len2=0;
        if(S[i]==str[j]){
            len1=1+solve(i+1,j+1,n,S,str,dp);
        }
        len2=max(solve(i+1,j,n,S,str,dp),solve(i,j+1,n,S,str,dp));
        
        return dp[i][j]=max(len1,len2);
    }
    int minimumNumberOfDeletions(string S) { 
        // code here
        string str=S;
        reverse(str.begin(),str.end());
        int n=S.size();
        
        vector<vector<int>> dp(n,vector<int> (n,-1));
        
        return n-solve(0,0,n,S,str,dp);
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends