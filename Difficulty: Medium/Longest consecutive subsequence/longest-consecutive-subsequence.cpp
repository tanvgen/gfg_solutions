//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      vector<int> v(1e5+1,-1);
      for(int i=0; i<N; i++){
          v[arr[i]]=i;
      }
      int s=0,e=0;
      int i=0;
      int ans=INT_MIN;
      while(i<1e5+1){
          if(v[i]!=-1){
              e++;
          }
          else{
              ans=max(ans,e-s);
              s=e;
          }
          
          i++;
      }
    //   int maxi=INT_MIN;
    //   int mini=INT_MAX;
    //   int ans=INT_MIN;
    //   for(int i=0; i<1e5+1; i++){
    //       if(v[i]!=-1){
    //           maxi=max(maxi,v[i]);
    //           mini=min(mini,v[i]);
    //           ans=max(ans,maxi-mini);
    //       }
         
    //   }
      return ans;
      
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends