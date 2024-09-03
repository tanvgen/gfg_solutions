//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    long long solve(int i,int j, int n, int k, vector<vector<int>> &arr, vector<vector<vector<long long>>> &dp){
        if(i>=n || j>=n || arr[i][j]>k || k<0) return 0;
        if(k-arr[i][j]==0 && i==n-1 && j==n-1) return 1;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        long long way1=0,way2=0;
        if(k>=arr[i][j]){
            way1=solve(i+1,j,n,k-arr[i][j],arr,dp);
            way2=solve(i,j+1,n,k-arr[i][j],arr,dp);
        }
        return dp[i][j][k]=way1+way2;
    }
    long long numberOfPath(int n, int k, vector<vector<int>> &arr){
        vector<vector<vector<long long>>> dp(n,vector<vector<long long>>(n,vector<long long>(k+1,-1)));
        return solve(0,0,n,k,arr,dp);
    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n, vector<int>(n, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends