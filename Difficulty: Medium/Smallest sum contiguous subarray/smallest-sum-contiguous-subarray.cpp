//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int smallestSumSubarray(vector<int>& a){
     
    int mini=*min_element(a.begin(),a.end());
    int n=a.size();
    int ans=mini;
    int sum=0;
    for(int i=0; i<n; i++){
        sum+=a[i];
        if(sum<ans){
            ans=sum;
        }
        if(sum>0) sum=0;
    }
    return ans;
      
  }
};


//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        
        int ans = ob.smallestSumSubarray(a);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends