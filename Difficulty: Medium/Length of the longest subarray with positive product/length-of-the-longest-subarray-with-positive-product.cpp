//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &arr,int n){
           //code here
           int len=0, num_neg=0, prev0=-1, firstneg=-1;
           
           for(int i=0; i<n; i++){
               if(arr[i]<0){
                   num_neg++;
                   if(firstneg==-1) firstneg=i;
               }
               if(arr[i]==0){
                   firstneg=-1;
                   num_neg=0;
                   prev0=i;
               }
               else{
                   if(num_neg%2==0){
                       len=max(len,i-prev0);
                   }
                   else{
                       len=max(len,i-firstneg);
                   }
               }
           }
           return len;
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends