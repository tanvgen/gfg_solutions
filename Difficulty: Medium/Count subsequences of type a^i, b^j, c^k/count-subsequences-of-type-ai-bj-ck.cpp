//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template 

class Solution{
  public:
    // s : given string
    // return the expected answer
    int mod=1e9+7;
    int fun(string &s) {
        //code here
        int a=0,b=0,c=0;
        
        int n=s.size();
        for(int i=0; i<n; i++){
            if(s[i]=='a'){
                a=(2*a%mod+1)%mod;
            }
            else if(s[i]=='b'){
                b=(2*b%mod+a)%mod;
            }
            else if(s[i]=='c'){
                c=(2*c%mod+b)%mod;
            }
        }
        
        return c;
    }
};

//{ Driver Code Starts.
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.fun(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends