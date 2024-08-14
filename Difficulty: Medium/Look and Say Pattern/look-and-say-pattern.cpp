//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    string lookandsay(int n) {
        // code here
        string s="1";
        
        for(int i=1; i<n; i++){
            int ctr=1;
            string temp="";
            for(int j=1; j<s.size(); j++){
                if(s[j-1]==s[j]){
                    ctr++;
                }
                else{
                    temp+=to_string(ctr)+s[j-1];
                    ctr=1;
                }
            }
            temp+=to_string(ctr)+s.back();
            s=temp;
        }
        return s;
    }   
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution obj;
        cout<<obj.lookandsay(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends