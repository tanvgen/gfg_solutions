//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int dp[101][101][201];
    bool solve(string &A, string &B, string &C, int i, int j, int k, int n, int m, int t){
        if(i==n && j==m && k==t) return dp[i][j][k]=1;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        
        bool result1=0,result2=0;
        if(A[i]==C[k]){
            result1=solve(A,B,C,i+1,j,k+1,n,m,t);
        }
        if(B[j]==C[k]){
            result2=solve(A,B,C,i,j+1,k+1,n,m,t);
        }
        
        return dp[i][j][k]=result1||result2;
    }
    bool isInterleave(string A, string B, string C) 
    {
        //Your code here
        int n=A.size();
        int m=B.size();
        int t=C.size();
        memset(dp,-1,sizeof(dp));
        return solve(A,B,C,0,0,0,n,m,t);
    }

};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends