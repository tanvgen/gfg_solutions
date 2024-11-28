//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i, int j, int N, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp){
        // if(i==N){
        //     if(j==W) return dp[i][j];
        //     else return 0;
        // }
        if(i>=N || j>W) return 0;
        //if(j>W) return dp[i][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int take=0;
        if(j+wt[i]<=W) take=val[i]+solve(i,j+wt[i],N,W,val,wt,dp);
        int ntake=solve(i+1,j,N,W,val,wt,dp);
        
        return dp[i][j]=max(take,ntake);
    }
    int knapSack(vector<int> &val, vector<int> &wt, int W)
    {
        // code here
        int N=val.size();
        vector<vector<int>> dp(N,vector<int> (W+1,-1));
        return solve(0,0,N,W,val,wt,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int W;
        cin >> W;
        cin.ignore();
        string str;
        getline(cin, str);
        stringstream ss(str);
        vector<int> val;
        int num;
        while (ss >> num) {
            val.push_back(num);
        }
        string str2;
        getline(cin, str2);
        stringstream ss2(str2);
        vector<int> wt;
        int num2;
        while (ss2 >> num2) {
            wt.push_back(num2);
        }
        Solution ob;
        cout << ob.knapSack(val, wt, W) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends