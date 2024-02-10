//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int minimizeSum(int n, vector<vector<int>>& triangle) {
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        dp[0][0]=triangle[0][0];
        
        for(int i=0; i<n; i++){
            for(int j=0; j<i+1; j++){
                if(i==0 && j==0) continue;
                if(i>0 && dp[i-1][j]!=INT_MAX){
                    dp[i][j]=min(dp[i][j],dp[i-1][j]+triangle[i][j]);
                }
                if(i>0 && j>0 && dp[i-1][j-1]!=INT_MAX){
                    dp[i][j]=min(dp[i][j], dp[i-1][j-1]+triangle[i][j]);
                }
            }
        }
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int ans=1e9;
        for(int i=0; i<n; i++){
            //cout<<dp[n-1][i]<<" ";
            ans=min(ans,dp[n-1][i]);
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
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends