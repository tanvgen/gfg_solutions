//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int FindWays(int n, int m, vector<vector<int>>blocked_cells){
	    int mod=1e9+7;
	    int dp[n+1][m+1];
	    for(int i=0; i<n+1; i++){
	        for(int j=0; j<m+1; j++){
	           // cout<<dp[i][j]<<" ";
	           dp[i][j]=0;
	        }
	    }
	    for(int i=0; i<n+1; i++){
	        dp[i][0]=-1;
	    }
	    for(int j=0; j<m+1; j++){
	        dp[0][j]=-1;
	    }
	    dp[1][1]=1;
	    for(auto it: blocked_cells){
	        int l=it[0];
	        int r=it[1];
	        dp[l][r]=-1;
	    }
	   // for(int i=0; i<n+1; i++){
	   //     for(int j=0; j<m+1; j++){
	   //         cout<<dp[i][j]<<" ";
	   //     }
	   //     cout<<endl;
	   // }
	    for(int i=1;i<n+1; i++){
	        for(int j=1; j<m+1; j++){
	            if(dp[i][j]==-1) continue;
	            if(dp[i-1][j]!=-1){
	                dp[i][j]+=(dp[i-1][j])%mod;
	            }
	            if(dp[i][j-1]!=-1){
	                dp[i][j]+=(dp[i][j-1])%mod;
	            }
	        }
	    }
	    if(dp[n][m]==-1){
	        return 0;
	    }
	    return (dp[n][m])%mod;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>>blocked_cells;
		for(int i = 0; i < k; i++){
			int x, y;
			cin >> x >> y;
			blocked_cells.push_back({x, y});
		}
		Solution obj;
		int ans = obj.FindWays(n, m, blocked_cells);
		cout << ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends