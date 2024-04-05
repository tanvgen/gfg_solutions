//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector<long long>> dp(N, vector<long long>(sum+1,0));
        
        for(int i=0; i<=sum; i++){
            if(i%coins[0]==0){
                dp[0][i]=1;
            }
        }
        for(int i=1; i<N; i++){
            for(int j=0; j<sum+1; j++){
                long long nottake=dp[i-1][j];
                long long take=0;
                if(coins[i]<=j){
                    take=dp[i][j-coins[i]];
                }
                
                dp[i][j]= take+nottake;
            }
        }
        return dp[N-1][sum];
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends