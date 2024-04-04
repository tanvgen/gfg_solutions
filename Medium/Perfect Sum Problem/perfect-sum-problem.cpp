//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        int mod=1e9+7;
        vector<vector<long long>> dp(n,vector<long long> (sum+1, 0));
        
        for(int i=0; i<n; i++){
            dp[i][0]=1+(arr[i]==0);
        }
        if(arr[0]!=0 && arr[0]<=sum){
            dp[0][arr[0]]=1;
        }
        
        for(int i=1; i<n; i++){
            for(int j=0; j<=sum; j++){
                int nottake=dp[i-1][j];
                
                int take=0;
                if(arr[i]<=j){
                    take=dp[i-1][j-arr[i]];
                }
                
                dp[i][j]= (take+nottake)%mod;
            }
        }
        return dp[n-1][sum] %mod;
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
	     
    }
    return 0;
}

// } Driver Code Ends