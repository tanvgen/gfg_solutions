//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  long long int wineSelling(vector<int>& Arr, int N){
      //Code here.
      vector<pair<int,int>> v;
      for(int i=0; i<N; i++){
          if(Arr[i]>0) v.push_back({Arr[i],i});
      }
      int m=v.size();
      int i=0,j=0;
      long long ans=0;
      while(i<m && j<N){
          if(Arr[j]>0){
              j++;
          }
          else{
              if(v[i].first>=abs(Arr[j])){
                  ans+=(abs(Arr[j]))*abs(j-v[i].second);
                  v[i].first+=Arr[j];
                  j++;
                  //cout<<ans<<" g"<<endl;
              }
              else{
                  //cout<<v[i].first<<endl;
                  ans+=(v[i].first)*abs(j-v[i].second);
                  Arr[j]+=v[i].first;
                  i++;
                  //cout<<ans<<endl;
              }
          }
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
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        long long int ans = ob.wineSelling(arr,n);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends