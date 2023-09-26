//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        sort(arr.begin(), arr.end());
        int n=arr.size();
        int l,r;
        for(int i=0; i<n-3; i++){
            for(int j=i+1; j<n-2; j++){
                l=j+1;
                r=n-1;
                while(l<r){
                if(arr[i]+arr[j]+arr[l]+arr[r]==k){
                     vector<int> temp;
                     temp.push_back(arr[i]);
                     temp.push_back(arr[j]);
                     temp.push_back(arr[l]);
                     temp.push_back(arr[r]);
                     s.insert(temp);
                     l++;
                     r--;
                }
                else if(arr[i]+arr[j]+arr[l]+arr[r]>k){
                    r--;
                }
                else{
                    l++;
                }
                }
            }
        }
        for(auto it:s){
            ans.push_back(it);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends