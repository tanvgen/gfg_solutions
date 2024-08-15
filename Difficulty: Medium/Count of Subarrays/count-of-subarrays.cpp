//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ll long long


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long

	ll countSubarray(int arr[], int n, int k) {
	    // code here
	    ll ans=0;
	    bool flag=false;
	    int idx=0;
	    for(int i=0; i<n; i++){
	        if(arr[i]>k){
	            ans+=(i-idx+1)*(n-i);
	            //cout<<ans<<endl;
	            idx=i+1;
	        }
	       // else if(arr[i]>k && flag==true){
	       //     ans+=(n-i);
	       // }
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