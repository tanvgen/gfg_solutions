//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToPre(string post_exp) {
        // Write your code here
        int n=post_exp.size();
        stack<string> st;
        int i=0;
        while(i<n){
            if((post_exp[i]>='a' && post_exp[i]<='z') || 
                (post_exp[i]>='A' && post_exp[i]<='Z')){
                 string temp="";
                 temp+=post_exp[i];
                 st.push(temp);
            }
            else{
                string t1=st.top(); st.pop();
                string t2=st.top(); st.pop();
                st.push(post_exp[i]+t2+t1);
            }
            i++;
        }
        return st.top();
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;

        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToPre(postfix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends