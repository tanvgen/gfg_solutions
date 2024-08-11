//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseWords (string s)
    {
        //code here.
        string ans;
        int n=s.size();
        stack<char> st;
        for(int i=0; i<n; i++){
            if(s[i]=='.'){
                while(!st.empty()){
                    char ch=st.top();
                    st.pop();
                    ans=ans+ch;
                }
                ans+='.';
            }
            else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            char ch=st.top();
            st.pop();
            ans=ans+ch;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends