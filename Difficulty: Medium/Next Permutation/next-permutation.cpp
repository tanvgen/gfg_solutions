//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> nextPermutation(vector<int> arr) {
        // code here
        int N=arr.size();
        int idx=-1;
        for(int i=N-2; i>=0; i--){
            if(arr[i]<arr[i+1]){
                idx=i;
                break;
            }
        }
        if(idx==-1) {
            reverse(arr.begin(), arr.end());
            return arr;
        }
        for(int i=N-1; i>idx; i--){
            if(arr[i]>arr[idx]){
                swap(arr[i],arr[idx]);
                break;
            }
        }
        sort(arr.begin()+idx+1, arr.end());
        return arr;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int n = arr.size();
        vector<int> ans = ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends