//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    // Should return true if there exists a triplet in the
    // array arr[] which sums to x. Otherwise false
    bool find3Numbers(int arr[], int n, int x) {
        // Your Code Here
        unordered_map<int,int> mp;
        // for(int i=0; i<n; i++){
        //     mp[arr[i]].push_back(i);
        // }
        for(int i=0; i<n; i++){
            //int sum=arr[i];
            
            for(int j=i+1; j<n; j++){
                int sum=arr[i]+arr[j];
                // cout<<i<<endl;
                // cout<<sum<<endl;
                if(mp[x-sum]>0){
                    return 1;
                }
            }
            mp[arr[i]]++;
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, X;
        cin >> n >> X;
        int i, A[n];
        for (i = 0; i < n; i++)
            cin >> A[i];
        Solution ob;
        cout << ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends