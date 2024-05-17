//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int solve(int n, vector<int>& nums, int k){
        int i=0,j=0,ans=0,ctr=0;
        
        while(j<n){
            
            ctr+=nums[j]%2;
                
            while(ctr>k){
                ctr-=nums[i]%2;
                i++;
            }
         
            ans+=(j-i+1);
            j++;
        }
        
        return ans;
    }
    int countSubarray(int n, vector<int>& nums, int k) {
        // Code here
        return solve(n,nums,k)-solve(n,nums,k-1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.countSubarray(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends