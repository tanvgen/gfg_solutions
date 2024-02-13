//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        vector<vector<int>> dp(N,vector<int>(N,0));
        //dp[0][0]=Matrix[0][0];
        for(int i=0; i<N; i++){
            dp[0][i]=Matrix[0][i];
        }
        for(int i=1; i<N; i++){
            for(int j=0; j<N; j++){
                if(i-1>=0){
                    dp[i][j]=max(dp[i][j],dp[i-1][j]+Matrix[i][j]);
                }
                if(i-1>=0 && j+1<N){
                    dp[i][j]=max(dp[i][j],dp[i-1][j+1]+Matrix[i][j]);
                }
                if(i-1>=0 && j-1>=0){
                    dp[i][j]=max(dp[i][j],dp[i-1][j-1]+Matrix[i][j]);
                }
            }
        }
        int ans=0;
        for(int i=0; i<N; i++){
            ans=max(ans, dp[N-1][i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends