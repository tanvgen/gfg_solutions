//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	int mod=1e9+7;
	ll solve(vector<ll> &dp, int n){
	    if(n==0) return 1;
	    if(n==1) return 2;
	    if(dp[n]!=-1) return dp[n];
	    
	    ll ways=0;
	    
	    ways=(ways+solve(dp,n-2))%mod;
	    ways=(ways+solve(dp,n-1))%mod;
	    
	    return dp[n]=ways;
	}
	ll countStrings(int n) {
	    // code here
	    vector<ll> dp(n+1,-1);
	   
	    return solve(dp,n);
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
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends