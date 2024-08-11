//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  //Expansion from center--O(N^2)
    string get_pal(string s, int l, int r){
        int n=s.size();
        while(l>=0 && r<n){
            if(s[l]!=s[r]) break;
            l--;
            r++;
        }
        return s.substr(l+1,r-l-1); //r-l-1 is the length of the substring
    }

    string longestPalin (string S) {
        // code here
        int n=S.size();
        string ans;
        
        for(int i=0; i<n; i++){
            string odd=get_pal(S,i,i);
            if(odd.size()>ans.size()){
                ans=odd;
            }
        }
        for(int i=0; i<n-1; i++){
            string even;
            if(S[i]==S[i+1]) even=get_pal(S,i,i+1);
            if(even.size()>ans.size()){
                ans=even;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends