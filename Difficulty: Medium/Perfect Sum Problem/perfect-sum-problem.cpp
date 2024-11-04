//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	const int mod=1e9+7;
	int solve(int i, int j, int arr[], int n, int sum, vector<vector<int>> &dp){
	    if(i==n){
	        if(j==sum) return 1;
	        else return 0;
	    }
	    
	    if(dp[i][j]!=-1) return dp[i][j];
	    
	    int take=0;
	    if(j+arr[i]<=sum) take=solve(i+1,j+arr[i],arr,n,sum,dp)%mod;
	    int ntake=solve(i+1,j,arr,n,sum,dp)%mod;
	    
	    return dp[i][j]=(take+ntake)%mod;
	    
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return solve(0,0,arr,n,sum,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends