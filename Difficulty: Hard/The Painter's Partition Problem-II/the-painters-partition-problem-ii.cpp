//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long possible_workers(int n, int arr[], long long val){
        long long ans=0;
        long long min_time=0;
        for(int i=0; i<n; i++){
            if(min_time+arr[i]<=val){
                min_time+=arr[i];
            }
            else{
                ans++;
                min_time=arr[i];
            }
        }
        ans++;
        return ans;
        
    }
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        long long low=*max_element(arr,arr+n);
        long long high=0;
        for(int i=0; i<n; i++){
            high+=arr[i];
        }
        while(low<=high){
            long long mid=(low+high)/2;
            if(possible_workers(n,arr,mid)>k){
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

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends