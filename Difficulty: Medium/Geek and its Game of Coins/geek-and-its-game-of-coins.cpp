//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
private:
    int solve(int n, int x, int y,vector<int>&dp,bool a) {
        if (n == 0) return 0;  
        if (dp[n] != -1) return dp[n];
        if (n >= 1 && solve(n - 1, x, y,dp,!a) == 0) return dp[n] = 1;
        if (n >= x && solve(n - x, x, y,dp,!a) == 0) return dp[n] = 1;
        if (n >= y && solve(n - y, x, y,dp,!a) == 0) return dp[n] = 1;
        
        return dp[n] = 0;
    }

public:
    int findWinner(int n, int x, int y) {
        bool a= true;
       vector<int>dp(n+1,-1);
        return solve(n, x, y,dp,a);
    }

};



//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        Solution obj;
        int res = obj.findWinner(n, x, y);

        cout << res << endl;
    }
}

// } Driver Code Ends