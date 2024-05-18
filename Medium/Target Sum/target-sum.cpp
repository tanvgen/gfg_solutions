//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    long long findTargetSumWays(int n, vector<int>& A, int target) {
        // Your code here
        int  mod=1e9+7;
        int sum=0;
        for(auto it: A){
            sum+=abs(it);
        }
        
        int k=(sum+target);
        
        if(k%2!=0 || k<0){
            return 0;
        }
        else {
            k=k/2;
        
        vector<vector<int>> dp(n,vector<int>(k+1,0));
        
        for(int i=0; i<n; i++){
            dp[i][0]=1;
        }
        if(A[0]<=k){
            dp[0][A[0]]=1;
        }
        
        for(int i=1; i<n; i++){
            for(int j=1; j<k+1; j++){
                int ntake=dp[i-1][j]%mod;
                int take=0;
                if(j>=A[i]){
                    take=dp[i-1][j-A[i]]%mod;
                }
                
                dp[i][j]=(take+ntake)%mod;
            }
        }
        
        return dp[n-1][k];
        }    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin >> N;
        vector<int> arr(N);

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout << ob.findTargetSumWays(N, arr, target);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends