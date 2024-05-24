//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string removeOuter(string& s) {
        // code here
        stack<char>st;
        string ans="";
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                if(st.empty()){
                    st.push('(');
                }
                else{
                    st.push('(');
                    ans=ans+'(';
                }
            }
            else{
                st.pop();
                if(!st.empty()){
                    ans=ans+')';
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;

        cout << obj.removeOuter(s) << "\n";
    }
}
// } Driver Code Ends