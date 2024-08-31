//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int mod = 1e9+7;
    long long countWays(int n, int k){
        // code here
        vector<long long> dp(n+1,0);
        long long m=k;
        dp[1]=m%mod;
        dp[2]=(m*m)%mod;
        
        for(int i=3; i<=n; i++){
            dp[i]=((dp[i-1]*(m-1))%mod+(dp[i-2]*(m-1))%mod)%mod;
        }
        
        return dp[n]%mod;
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends