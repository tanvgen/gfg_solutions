//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int countWays(int n, string s){
        // code here
        int mod=1003;
        
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,0)));
        
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<n; j++){
                if(i>j) continue;
                for(int istrue=0; istrue<=1; istrue++){
                    if(i==j){
                        if(istrue==0){
                            dp[i][j][0]=s[i]=='F';
                        }
                        else{
                            dp[i][j][1]=s[i]=='T';
                        }
                        continue;
                    }
                    int ways=0;
                    for(int k=i+1; k<j; k=k+2){
                        int ltrue=dp[i][k-1][1];
                        int lfalse=dp[i][k-1][0];
                        int rtrue=dp[k+1][j][1];
                        int rfalse=dp[k+1][j][0];
                        
                        if(s[k]=='|'){
                            if(istrue==1) ways+=((ltrue*rtrue)%mod+(ltrue*rfalse)%mod+(lfalse*rtrue)%mod)%mod;
                            else ways+=(lfalse*rfalse)%mod;
                        }
                        else if(s[k]=='&'){
                            if(istrue==1) ways+=(ltrue*rtrue)%mod;
                            else ways+=((lfalse*rfalse)%mod+(ltrue*rfalse)%mod+(lfalse*rtrue)%mod)%mod;
                        }
                        else{
                            if(istrue==1) ways+=((lfalse*rtrue)%mod+(ltrue*rfalse)%mod)%mod;
                            else ways+=((ltrue*rtrue)%mod+(lfalse*rfalse)%mod)%mod;
                        }
                    }
                    dp[i][j][istrue]=ways%mod;
                }
            }
        }
        return dp[0][n-1][1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.countWays(n, s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends