//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
class Solution
{
  public:
    // function to count the total  
    // number of ways to sum up to 'N' 
    int mod=1e9+7;
    int solve(int arr[], int m, int N, vector<int> &dp){
        if(N==0) return 1;
        if(N<0) return 0;
        if(dp[N]!=-1) return dp[N];
        
        int ways=0;
        for(int i=0; i<m; i++){
            ways=(ways+solve(arr,m,N-arr[i],dp))%mod;
        }
        return dp[N]=(ways)%mod;
    }
    int countWays(int arr[], int m, int N) 
    { 
      //code here.
      vector<int> dp(N+1,-1);
      return solve(arr,m,N,dp);
    } 
    
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int m,n ;
	        cin>>m>>n;
	        int arr[m];
	        for(int i = 0;i<m;i++)
	            cin>>arr[i];
	        Solution ob;     
	        cout<<ob.countWays(arr,m,n)<<endl;
	    }
}
// } Driver Code Ends