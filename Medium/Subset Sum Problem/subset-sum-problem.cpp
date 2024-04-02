//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        int k=sum;
        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    // Base case: If the target sum is 0, we can always achieve it by taking no elements
    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }

    // Base case: If the first element of 'arr' is less than or equal to 'k', set dp[0][arr[0]] to true
    if (arr[0] <= k) {
        dp[0][arr[0]] = true;
    }

    // Fill the DP array iteratively
    for (int ind = 1; ind < n; ind++) {
        for (int target = 1; target <= k; target++) {
            // If we don't take the current element, the result is the same as the previous row
            bool notTaken = dp[ind - 1][target];

            // If we take the current element, subtract its value from the target and check the previous row
            bool taken = false;
            if (arr[ind] <= target) {
                taken = dp[ind - 1][target - arr[ind]];
            }

            // Store the result in the DP array for the current subproblem
            dp[ind][target] = notTaken || taken;
        }
    }

    // The final result is stored in dp[n-1][k]
    return dp[n - 1][k];
    //     bool dp[n][sum+1];
    //     for(int i=0; i<n; i++){
    //         for(int j=0; j<=sum; j++){
    //             dp[i][j]=false;
    //         }
    //     }
    //   // vector<vector<bool>> dp(n, vector<bool>(sum+1, false));
        
    //     for(int i=0; i<n; i++){
    //         dp[i][0]=true;
    //     }
    //     if(arr[0]<=sum) {
    //         dp[0][arr[0]]=true;
    //     }
        
    //     for(int i=1; i<n; i++){
    //         for(int j=1; j<=sum; j++){
    //             bool nottaken=dp[i-1][j];
    //             bool taken=false;
    //             if(arr[i]<=sum){
    //                 taken=dp[i-1][j-arr[i]];
    //             }
    //             dp[i][j]=nottaken||taken;
    //         }
    //     }
    //     return dp[n-1][sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends