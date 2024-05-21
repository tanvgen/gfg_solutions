//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        // Code here
        int mod=1e9+7;
        
        vector<vector<int>> dp(n,vector<int>(m,0));
        if(grid[0][0]==1){
            return 0;
        }
        for(int i=0; i<n; i++){
            if(grid[i][0]==0){
                dp[i][0]=1;
            }
            else{
                break;
            }
        }
        for(int i=0; i<m; i++){
            if(grid[0][i]==0){
                dp[0][i]=1;
            }
            else{
                break;
            }
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(grid[i][j]==1){
                    dp[i][j]=0;
                }
                else{
                    dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
                }
            }
        }
        return dp[n-1][m-1];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends