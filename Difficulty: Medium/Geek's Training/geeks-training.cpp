//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int i, int j, vector<vector<int>>& arr, int n, vector<vector<int>>& dp){
        if(i>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(j==0) return dp[i][j]=arr[i][j]+max(solve(i+1,j+1,arr,n,dp),solve(i+1,j+2,arr,n,dp));
        if(j==1) return dp[i][j]=arr[i][j]+max(solve(i+1,j-1,arr,n,dp),solve(i+1,j+1,arr,n,dp));
        if(j==2) return dp[i][j]=arr[i][j]+max(solve(i+1,j-1,arr,n,dp),solve(i+1,j-2,arr,n,dp));
        
    }
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        vector<vector<int>> dp(n,vector<int>(3,-1));
        int ans=0;
        
        for(int j=0; j<3; j++){
            ans=max(ans,solve(0,j,arr,n,dp));
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
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends