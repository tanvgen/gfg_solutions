class Solution {
  public:
    bool solve(int i, int sum, int n,vector<int> &nums, vector<vector<int>> &dp){
        if(sum==0) return 1;
        if(i>=n || sum<0) return 0;
        if(dp[i][sum]!=-1) return dp[i][sum];

        return dp[i][sum]=solve(i+1,sum,n,nums,dp)||solve(i+1,sum-nums[i],n,nums,dp);
    }
    bool isSubsetSum(vector<int>& nums, int sum) {
        // code here
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return solve(0,sum,n,nums,dp);
    }
};