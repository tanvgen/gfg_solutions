class Solution {
  public:
    int solve(int i, vector<int> &height, int n, vector<int> &dp){
        if(i==n-1) return 0;
        //if(i==n-2) return abs(heights[n-2]-heights[n-1]);
        if(dp[i]!=-1) return dp[i];
        
        int cost1=abs(height[i]-height[i+1])+solve(i+1,height,n,dp);
        
        int cost2=INT_MAX;
        if(i+2<n){
            cost2=abs(height[i]-height[i+2])+solve(i+2,height,n,dp);
        }
        
        return dp[i]=min(cost1,cost2);
    }
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        vector<int> dp(n,-1);
        return solve(0, height, n, dp);
    }
};