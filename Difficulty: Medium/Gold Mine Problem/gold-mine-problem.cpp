//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        vector<vector<int>> dp(n,vector<int> (m,0));
        
        for(int i=0; i<n; i++) dp[i][0]=M[i][0];
        
        for(int j=1; j<m; j++){
            for(int i=0; i<n; i++){
                int c1=INT_MIN,c2=INT_MIN,c3=INT_MIN;
                c1=dp[i][j-1];
                if(i!=0) c2=dp[i-1][j-1];
                if(i!=n-1) c3=dp[i+1][j-1];
                
                dp[i][j]=M[i][j]+max({c1,c2,c3});
            }
        }
        int ans=0;
        for(int i=0; i<n; i++){
            ans=max(ans,dp[i][m-1]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends