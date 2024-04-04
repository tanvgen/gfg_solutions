//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int mod=1e9+7;
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=arr[i];
        }
        int k=(sum-d);
        if(k<0 || k%2!=0){
            return 0;
        }
        else{
        
        k=k/2;
        vector<vector<int>> dp(n, vector<int>(k+1,0));
        
        for(int i=0; i<n; i++){
            dp[i][0]=1+(arr[i]==0);
        }
        if(arr[0]!=0 && arr[0]<=k){
            dp[0][arr[0]]=1;
        }
        
        for(int i=1; i<n; i++){
            for(int j=0; j<=k; j++){
                int nottake=dp[i-1][j]%mod;
                
                int take=0;
                if(arr[i]<=j){
                    take=dp[i-1][j-arr[i]]%mod;
                }
                dp[i][j]=(nottake+take)%mod;
            }
        }
        return dp[n-1][k]%mod;   
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends