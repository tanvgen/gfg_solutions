//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findMinCost(string x, string y, int costX, int costY) {
        // Your code goes here
        int n=x.size();
        int m=y.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        // for(int i=0; i<=n; i++){
        //     dp[i][0]=0;
        // }
        // for(int i=0; i<=m; i++){
        //     dp[0][i]=0;
        // }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(x[i-1]==y[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        int ans=dp[n][m];
        //cout<<ans<<endl;
        return (n-ans)*costX+(m-ans)*costY;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;

        int costX, costY;
        cin >> costX >> costY;

        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends