//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	#define ll long long
	int mod=1e9+7;
	ll solve(vector<ll> &dp, int n){
	    //if(n==0) return 1;
	    if(n==1) return 2;
	    if(n==2) return 3;
	    if(dp[n]!=-1) return dp[n];
	    
	    ll ways=0;
	    
	    ways=(ways+solve(dp,n-2))%mod;
	    ways=(ways+solve(dp,n-1))%mod;
	    
	    return dp[n]=ways;
	}
	int TotalWays(int N)
	{
	    // Code here
	    vector<int> dp(N+1,-1);
	    ll ans=solve(N,dp)%mod;
	    
	    return (ans*ans)%mod;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends