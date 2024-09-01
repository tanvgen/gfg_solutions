//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int solve(int i, vector<int>&arr, int n, vector<int> &dp){
	    if(i>=n) return 0;
	    if(dp[i]!=-1) return dp[i];
	    
	    int sum1=0,sum2=0;
	    sum1+=arr[i]+solve(i+2,arr,n,dp);
	    sum2+=solve(i+1,arr,n,dp);
	    
	    return dp[i]=max(sum1,sum2);
	}
	int findMaxSum(vector<int>&arr, int n) {
	    // code here
	    vector<int> dp(n,-1);
	    return solve(0,arr,n,dp);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends