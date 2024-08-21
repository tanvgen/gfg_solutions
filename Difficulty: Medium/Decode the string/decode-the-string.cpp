//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
class Solution{
public:
    string decodedString(string s){
        // code here
        stack<char> st;
        int n=s.size();
        string ans="";
        for(int i=0; i<n; i++){
            if(s[i]==']'){
                string temp="";
                while(!st.empty() && st.top()!='['){
                    temp=st.top()+temp;
                    st.pop();
                }
                //cout<<temp<<endl;
                st.pop();
                string num="";
                while(!st.empty() && st.top()>='0' && st.top()<='9'){
                    num=st.top()+num;
                    st.pop();
                }
                int ctr=stoi(num);
                //cout<<ctr<<endl;
                for(int i=0; i<ctr; i++){
                    ans+=temp;
                }
                //cout<<ans<<endl;
                for(int i=0; i<ans.size(); i++){
                    st.push(ans[i]);
                }
                ans="";
            }
            else st.push(s[i]);
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends