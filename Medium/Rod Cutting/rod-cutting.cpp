//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        int W=n;
        int wt[n];
        for(int i=0; i<n; i++){
            wt[i]=i+1;
        }
        vector<vector<int>> dp(n, vector<int>(W+1,0));
        for(int i=wt[0]; i<=W; i++){
            dp[0][i]=(i/wt[0])*price[0];
        }
        for(int i=0; i<n; i++){
            dp[i][0]=0;
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<W+1; j++){
                int ntake=dp[i-1][j];
                int take=INT_MIN;
                if(wt[i]<=j){
                    take=price[i]+dp[i][j-wt[i]];
                }
                dp[i][j]=max(ntake,take);
            }
        }
        return dp[n-1][W];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends