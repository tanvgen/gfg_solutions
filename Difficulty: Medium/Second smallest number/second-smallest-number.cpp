//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    string secondSmallest(int S, int D){
        // code here 
        if(D*9<=S) return "-1";
        string ans(D,'0');
        int i=D-1;
        while(S>9){
            ans[i]='9';
            i--;
            S-=9;
        }
        
        if(i>0){
            ans[i]=S-1+'0';
            ans[0]='1';
        }
        else{
            ans[0]=S+'0';
        }
        
        for(int i=D-1; i>0; i--){
            if(ans[i]!=ans[i-1]){
                ans[i]--;
                ans[i-1]++;
                break;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends