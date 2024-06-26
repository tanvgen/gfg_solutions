//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minCoins(vector<int> &coins, int M, int V) 
	{ 
	    // Your code goes here
	    vector<vector<int>> dp(M,vector<int> (V+1,0));
	    
	    for(int i=0; i<=V; i++){
	        if(i%coins[0]==0){
	            dp[0][i]=i/coins[0];
	        }
	        else{
	            dp[0][i]=1e9;
	        }
	    }
	    
	    for(int i=1; i<M; i++){
	        for(int j=1; j<=V; j++){
	            int ntake=dp[i-1][j];
	            int take=1e9;
	            if(j>=coins[i]){
	                take=1+dp[i][j-coins[i]];
	            }
	            dp[i][j]=min(take,ntake);
	        }
	    }
	    int ans=dp[M-1][V];
	    if(ans>=1e9){
	        return -1;
	    }
	    else{
	        return ans;
	    }
	    
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        vector<int> coins(m);
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends