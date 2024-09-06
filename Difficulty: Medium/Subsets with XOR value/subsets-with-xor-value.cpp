//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int solve(int i, int xorr, vector<int> arr, int N, int K, vector<vector<int>> &dp){
        if(i>=N){
            if(xorr==K) return 1;
        return 0;
        }
        
        if(dp[i][xorr]!=-1) return dp[i][xorr];
        
        int take=solve(i+1,xorr^arr[i],arr,N,K,dp);
        int ntake=solve(i+1,xorr,arr,N,K,dp);
        
        return dp[i][xorr]=take+ntake;
    }
    int subsetXOR(vector<int> arr, int N, int K) {
        // code here
        vector<vector<int>> dp(N,vector<int> (1001,-1));
        return solve(0,0,arr,N,K,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}
// } Driver Code Ends