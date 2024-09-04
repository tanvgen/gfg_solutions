//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long solve(int i, int j, int n, int arr[], vector<vector<long long>> &dp){
        if(i>=n || j<0 || i>j) return 0;
        //if(arr[i]==arr[j]) return arr[i];
        if(dp[i][j]!=-1) return dp[i][j];
        
        long long way1=arr[i]+min(solve(i+2,j,n,arr,dp),solve(i+1,j-1,n,arr,dp));
        long long way2=arr[j]+min(solve(i+1,j-1,n,arr,dp),solve(i,j-2,n,arr,dp));
        
        return dp[i][j]=max(way1,way2);
    }
    long long maximumAmount(int n, int arr[]){
        // Your code here
        vector<vector<long long>> dp(n,vector<long long>(n,-1));
        
        return solve(0,n-1,n,arr,dp);
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(n,a)<<endl;
	}
	return 0;
}
// } Driver Code Ends