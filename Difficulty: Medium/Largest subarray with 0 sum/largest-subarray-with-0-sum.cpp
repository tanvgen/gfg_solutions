//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        // Your code here
        // vector<int> presum(n,0);
        // presum[0]=arr[0];
        // for(int i=1; i<n; i++){
        //     presum[i]=arr[i]+presum[i-1];
        // }
        int len=0;
        int sum=0;
        int i=0, j=0;
        unordered_map<int,int>mp;
        while(j<n){
            sum+=arr[j];
            if(sum==0){
                len=max(len,j+1);
            }
            if(mp.find(sum)!=mp.end()){
                len=max(len,j-mp[sum]);
                //i=j;
            }
            else{
                mp[sum]=j;
            }
            j++;
        }
        return len;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i) {
            cin >> array1[i];
        }
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;
    }
    return 0;
}

// } Driver Code Ends