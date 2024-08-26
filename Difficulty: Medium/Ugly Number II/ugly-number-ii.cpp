//{ Driver Code Starts
//Initial Template for C++

// {Driver code starts
#include<bits/stdc++.h>
using namespace std;

//}Driver code ends


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    int uglyNumber(int n)
    {
        //your code here
        int i2,i3,i5;
        i2=i3=i5=1;
        vector<int> dp(n+1,0);
        dp[1]=1;
        for(int i=2; i<=n; i++){
            int i2uglynum=dp[i2]*2;
            int i3uglynum=dp[i3]*3;
            int i5uglynum=dp[i5]*5;
            int mini=min({i2uglynum,i3uglynum,i5uglynum});
            
            dp[i]=mini;
            
            if(mini==i2uglynum){
                i2++;
            }
            if(mini==i3uglynum){
                i3++;
            }
            if(mini==i5uglynum){
                i5++;
            }
        }
        return dp[n];
    }
    
};



//{ Driver Code Starts.

//{Driver code starts
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        int res;
        res=ob.uglyNumber(n);
        
        cout<<res;
        cout<<"\n";    
    }
}



// } Driver Code Ends