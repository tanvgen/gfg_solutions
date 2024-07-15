//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToInfix(string pre_exp) {
        // Write your code here
        int n=pre_exp.size();
        stack<string> st;
        for(int i=n-1; i>=0; i--){
            if((pre_exp[i]>='a' && pre_exp[i]<='z') ||
               (pre_exp[i]>='A' && pre_exp[i]<='Z')){
                   string temp1="";
                   temp1+=pre_exp[i];
                   st.push(temp1);
            }
            else{
                string t1=st.top(); st.pop();
                string t2=st.top(); st.pop();
                st.push('('+t2+pre_exp[i]+t1+')');
            }
            
        }
        string temp2=st.top();
        reverse(temp2.begin(), temp2.end());
        for(int i=0; i<temp2.size(); i++){
            if(temp2[i]=='(') temp2[i]=')';
            else if(temp2[i]==')') temp2[i]='(';
        }
        return temp2;
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends