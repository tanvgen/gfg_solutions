//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int> dp;
       int maxi=1;
       for(int i=0; i<n; i++){
           auto it=lower_bound(dp.begin(),dp.end(),a[i]);
           if(it==dp.end()) dp.push_back(a[i]);
           else{
               int idx=it-dp.begin();
               dp[idx]=a[i];
           }
           maxi=max(maxi,(int)dp.size());
       }
       
       //int maxi=*max_element(dp.begin(),dp.end());
       
       return maxi;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends