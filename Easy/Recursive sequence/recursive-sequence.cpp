//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long sequence(int n){
        // code here
        int mod=1e9+7;
        long long dp[n+1];
        long long sum=0;
        long long ctr=1;
        for(int i=1; i<=n; i++){
            long long m=1;
            for(int j=1; j<=i; j++){
                m=(m*ctr)%mod;
                ctr++;
            }
            sum=(sum+m)%mod;
        }
        return sum%mod;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends