//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
     int solve(int N, int K, int target, vector<int>& coins, int ind, vector<vector<int>>& dp){
        if(ind==N) return 0;
        if(K>0 and target==0) return 0;
        if(K==0 and target!=0) return 0;
        if(K==0 and target==0) return 1;
        if(dp[K][target]!=-1) return dp[K][target];
        int take=0,nottake=0;
        if(target>=coins[ind]) take=solve(N,K-1,target-coins[ind],coins,ind,dp);
        nottake=solve(N,K,target,coins,ind+1,dp);
        return dp[K][target]=take || nottake;
    }


    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        // code here
        vector<vector<int>>dp(K+1,vector<int>(target+1,-1));
        return solve(N,K,target,coins,0,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends