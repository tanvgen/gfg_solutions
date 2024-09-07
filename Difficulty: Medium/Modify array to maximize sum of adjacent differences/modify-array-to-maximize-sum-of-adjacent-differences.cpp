//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{


	public:
	//bool flag shows if we have changed the previous element or not, 
	//1- changed to 1, 0- as it is
	int solve(int i, int arr[], int N, vector<vector<int>> &dp, bool flag){
	    if(i>=N) return 0;
	    if(dp[i][flag]!=-1) return dp[i][flag];
	    
	    int a,b;
	    if(flag==1){ //arr[i-1] changed to 1
	        a=abs(1-1)+solve(i+1,arr,N,dp,1); //arr[i-1] & arr[i] both changed to 1, also flag 1 kardia coz arr[i] is changed to 1 now
	        b=abs(arr[i]-1)+solve(i+1,arr,N,dp,0); //arr[i] as it is raha toh flag 0 rahega  
	        
	    }
	    else{ //arr[i-1] is as it is
	        a=abs(arr[i]-arr[i-1])+solve(i+1,arr,N,dp,0);
	        b=abs(arr[i-1]-1)+solve(i+1,arr,N,dp,1);
	    }
	    
	    return dp[i][flag]=max(a,b);
	}
	int maximumDifferenceSum(int arr[], int N) 
	{ 
	    // Your code goes here
	    vector<vector<int>> dp(N,vector<int> (2,-1));
	    return max(solve(1,arr,N,dp,0),solve(1,arr,N,dp,1));
	} 


};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.maximumDifferenceSum(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends