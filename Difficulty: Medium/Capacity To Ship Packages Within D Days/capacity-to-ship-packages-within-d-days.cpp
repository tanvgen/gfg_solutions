//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int solve(int arr[], int n, int wt){
        int num_days=0;
        int total_weight=0;
        for(int i=0; i<n; i++){
            if(total_weight+arr[i]<=wt){
                total_weight+=arr[i];
            }
            else{
                num_days++;
                total_weight=arr[i];
            }
        }
        num_days++;
        return num_days;
    }
    int leastWeightCapacity(int arr[], int n, int d) {
        // code here
        int mxwt=0;
        for(int i=0; i<n; i++){
            mxwt+=arr[i];
        }
        int low=*max_element(arr,arr+n);
        int high=mxwt;
        
        while(low<=high){
            int mid=(low+high)/2;
            if(solve(arr,n,mid)>d){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, D;
        cin >> N;

        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        cin >> D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr, N, D) << endl;
    }
    return 0;
}
// } Driver Code Ends