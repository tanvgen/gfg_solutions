class Solution {

  public:
    int solve(int i, int currsum, int n, int tsum, vector<int> &arr, vector<vector<int>> &dp){
        if(i>=n){
            int s1=currsum;
            int s2=tsum-currsum;
            
            return abs(s1-s2);
        }
        if(dp[i][currsum]!=-1) return dp[i][currsum];
        
        int take=solve(i+1,currsum+arr[i],n,tsum,arr,dp);
        int ntake=solve(i+1,currsum,n,tsum,arr,dp);
        
        return dp[i][currsum]=min(take,ntake);
    }
    int minDifference(vector<int>& arr) {
        // Your code goes here
        int n=arr.size();
        int tsum=0;
        for(int i=0; i<n; i++) tsum+=arr[i];
        
        vector<vector<int>> dp(n,vector<int>(tsum+1,-1));
        
        return solve(0,0,n,tsum,arr,dp);
    }
};
