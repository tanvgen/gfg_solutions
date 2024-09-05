//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    long long solve(int i, int N, int r[], int g[], int b[], vector<vector<long long>> &dp, int prev){
        if(i>=N) return 0;
        if(dp[i][prev]!=-1) return dp[i][prev];
        
        long long taker=1e11, takeg=1e11, takeb=1e11;
        
        if(prev==0){
            taker=r[i]+solve(i+1,N,r,g,b,dp,1);
            takeg=g[i]+solve(i+1,N,r,g,b,dp,2);
            takeb=b[i]+solve(i+1,N,r,g,b,dp,3);
        }
        else if(prev==1){
            takeg=g[i]+solve(i+1,N,r,g,b,dp,2);
            takeb=b[i]+solve(i+1,N,r,g,b,dp,3);
        }
        else if(prev==2){
            taker=r[i]+solve(i+1,N,r,g,b,dp,1);
            takeb=b[i]+solve(i+1,N,r,g,b,dp,3);
        }
        else{
            taker=r[i]+solve(i+1,N,r,g,b,dp,1);
            takeg=g[i]+solve(i+1,N,r,g,b,dp,2);
        }
        
        return dp[i][prev]=min(taker,min(takeg,takeb));
    }
    long long int distinctColoring(int N, int r[], int g[], int b[]){
        // code here 
        vector<vector<long long>> dp(N,vector<long long>(4,-1));
        return solve(0,N,r,g,b,dp,0);
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
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends