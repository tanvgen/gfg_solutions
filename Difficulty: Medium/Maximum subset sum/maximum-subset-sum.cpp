//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {

  public:
    long long solve(int i, int N, vector<int> &A, vector<long long> &dp){
        if(i>=N) return 0;
        if(dp[i]!=-1) return dp[i];
        
        long long take=0,ntake=0;
        
        take=A[i]+solve(i+1,N,A,dp);
        if(i+1<N) ntake=A[i+1]+solve(i+2,N,A,dp);
        
        long long sum=max(take,ntake);
        
        return dp[i]=sum;
    }
    long long findMaxSubsetSum(int N, vector<int> &A) {
        // code here
        vector<long long> dp(N,-1);
        return solve(0,N,A,dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends