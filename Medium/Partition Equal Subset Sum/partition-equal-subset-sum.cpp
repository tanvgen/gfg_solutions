//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0; i<N; i++){
            sum+=arr[i];
        }
        if(sum%2!=0){
            return false;
        }
        else{
            sum=sum/2;
            vector<vector<bool>> dp(N, vector<bool> (sum+1, false));
            for(int i=0; i<N; i++){
                dp[i][0]=true;
            }
            if(arr[0]<=sum){
                dp[0][arr[0]]=true;
            }
            for(int i=1; i<N; i++){
                for(int j=1; j<=sum; j++){
                    bool nottaken=dp[i-1][j];
                    bool taken=false;
                    if(arr[i]<=j){
                        taken=dp[i-1][j-arr[i]];
                    }
                    dp[i][j]=taken||nottaken;
                }
            }
            return dp[N-1][sum];
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends