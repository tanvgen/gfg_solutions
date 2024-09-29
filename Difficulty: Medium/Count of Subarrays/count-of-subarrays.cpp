//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ll long long


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
    //  consider the test case 30 4 23 6 to understand it better
	ll countSubarray(int arr[], int n, int k) {
	    // code here
	    ll ans=0,sec_num=0;
        for(int i=0;i<n;i++){
            if(arr[i]>k){
                sec_num=i+1;
            }

            ans+=sec_num;
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
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.countSubarray(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends