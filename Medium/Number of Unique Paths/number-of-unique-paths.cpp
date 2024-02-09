//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        int dp[a+1][b+1];
        for(int i=0; i<a+1; i++){
            dp[i][0]=0;
        }
        for(int j=0; j<b+1; j++){
            dp[0][j]=0;
        }
        dp[1][1]=1;
        
        
        for(int i=1; i<a+1; i++){
            for(int j=1; j<b+1; j++){
               if(i==1 && j==1) continue;
               else
               {
                   dp[i][j]=dp[i-1][j]+dp[i][j-1];
               }
            }
        }
        // for(int i=0; i<a+1; i++){
        //     for(int j=0; j<b+1; j++){
        //       cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return dp[a][b];
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends