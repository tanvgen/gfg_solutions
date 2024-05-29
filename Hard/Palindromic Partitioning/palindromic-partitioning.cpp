//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool pcheck(int i, int j, string s){
        while(i<j){
            if(s[i]!=s[j]) return 0;
            i++;
            j--;
        }
        return 1;
    }
    int palindromicPartition(string str)
    {
        // code here
        int n=str.size();
        vector<int> dp(n+1,0);
        for(int i=n-1; i>=0; i--){
            int mini=INT_MAX;
            for(int j=i; j<n; j++){
                if(pcheck(i,j,str)){
                    mini=min(mini,dp[j+1]+1);
                }
            }
            dp[i]=mini;
        }
        return dp[0]-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends