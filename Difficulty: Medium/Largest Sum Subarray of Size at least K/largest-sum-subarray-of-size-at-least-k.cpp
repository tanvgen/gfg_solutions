//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:    
    //#define long long ll;
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        long long sum=0;
        for(long long i=0; i<k; i++){
            sum+=a[i];
        }
        long long kadane=0;
        long long ans=sum;
        for(long long i=k; i<n; i++){
            sum+=a[i];
            sum-=a[i-k];
            
            kadane+=a[i-k];
            kadane=max((long long) 0,kadane);
            
            ans=max(ans,sum+kadane);
        }
        return ans;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends