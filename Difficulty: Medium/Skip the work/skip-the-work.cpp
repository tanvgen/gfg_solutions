//{ Driver Code Starts
#include <iostream>
using namespace std;

// } Driver Code Ends

#include <bits/stdc++.h>
class Solution
{
  public:
    // int solve(int i, bool flag, int A[], int N, vector<vector<int>> &dp){
    //     if(i>=N) return 0;
        
    //     if(dp[i][flag]!=-1) return dp[i][flag];
        
    //     int ans=INT_MAX;
    //     if(flag==1){
    //         int skip=solve(i+1,!flag,A,N,dp);
    //         int nskip=A[i]+solve(i+1,flag,A,N,dp);
            
    //         ans=min(skip,nskip);
    //     }
    //     else{
    //         ans=A[i]+solve(i+1,!flag,A,N,dp);
    //     }
        
    //     return dp[i][flag]=ans;
    // }
    int minAmount(int A[] , int N)
    {
        //code here.
        vector<vector<int>> dp(N, vector<int>(2,-1));
        dp[0][1]=0,dp[0][0]=A[0];
        for(int i=1; i<N; i++){
            for(int flag=0; flag<=1; flag++){
                if(flag==1){
                    int skip=dp[i-1][0];
                    int nskip=A[i]+dp[i-1][1];
                    dp[i][flag]=min(skip,nskip);
                }
                else{
                    dp[i][flag]=A[i]+dp[i-1][1];
                }
            }
        }
        return dp[N-1][1];
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
            int arr[n];
            for(int i = 0;i<n;i++)
                cin>>arr[i];
            Solution ob;    
            cout<<ob.minAmount(arr,n)<<endl;    
        }
}
// } Driver Code Ends