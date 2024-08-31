//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	int mod=1e9+7;
	    int solve(int i, string &str, int n, vector<long long> &dp){
	        if(i>=n) return true;
	        if(dp[i]!=-1) return dp[i];
	        
	        int onech=0,twoch=0;
	        if(str[i]>='1' && str[i]<='9'){
	            onech=solve(i+1,str,n,dp);
	        }
	        string temp=str.substr(i,2);
	        if(i<n-1 && temp>="10" && temp<="26"){
	            twoch=solve(i+2,str,n,dp);
	        }
	        return dp[i]=(onech+twoch)%mod;
	    }
		int CountWays(string str){
		    // Code here
		    int n=str.size();
		    vector<long long> dp(n,-1);
		    return solve(0,str,n,dp);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends