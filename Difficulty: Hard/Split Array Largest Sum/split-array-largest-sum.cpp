//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int possible_subarrays(int arr[], int N, int val){
        int ans=0;
        int sum=0;
        for(int i=0; i<N; i++){
            if(sum+arr[i]<=val){
                sum+=arr[i];
            }
            else{
                sum=arr[i];
                ans++;
            }
        }
        ans++;
        return ans;
    }
    int splitArray(int arr[] ,int N, int K) {
        // code here
        int low=*max_element(arr,arr+N);
        int high=0;
        for(int i=0; i<N; i++){
            high+=arr[i];
        }
        while(low<=high){
            int mid=(low+high)/2;
            if(possible_subarrays(arr,N,mid)>K){
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
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends