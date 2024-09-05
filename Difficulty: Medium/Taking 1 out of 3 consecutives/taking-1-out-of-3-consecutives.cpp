//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int minSum(vector<int>& arr) {
        // Write your code here
        int n=arr.size();
        if(n<=2) return 0;
        
        vector<int> dp(n,-1);
        
        dp[0]=arr[0],dp[1]=arr[1],dp[2]=arr[2];
        
        for(int i=3; i<n; i++){
            dp[i]=arr[i]+min(dp[i-1],min(dp[i-2],dp[i-3]));
        }
        
        return min(dp[n-1],min(dp[n-2],dp[n-3]));
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minSum(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends