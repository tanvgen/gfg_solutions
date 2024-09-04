//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long solve(int i, int j, vector<vector<int>> &keypad, vector<vector<vector<long long>>> &dp, int n){
        if(i<0 || i>=4 || j<0 || j>=3 || keypad[i][j]==-1) return 0;
        if(n==1) return 1;
        
        if(dp[n][i][j]!=-1) return dp[n][i][j];
        
        long long ctr=solve(i,j,keypad,dp,n-1)+
                      solve(i-1,j,keypad,dp,n-1)+
                      solve(i+1,j,keypad,dp,n-1)+
                      solve(i,j-1,keypad,dp,n-1)+
                      solve(i,j+1,keypad,dp,n-1);
                      
        return dp[n][i][j]=ctr;
    }
    long long getCount(int n) {
        // Your code goes here
        vector<vector<int>> keypad={{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
        
        vector<vector<vector<long long>>> dp(n+1,vector<vector<long long>> (4,vector<long long>(3,-1)));
        
        long long ans=0;
        
        for(int i=0; i<4; i++){
            for(int j=0; j<3; j++){
                if(keypad[i][j]!=-1){
                    ans+=solve(i,j,keypad,dp,n);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends