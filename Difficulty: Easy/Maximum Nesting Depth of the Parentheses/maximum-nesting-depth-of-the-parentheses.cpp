//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int maxDepth(string s) {
        // code here
        int ctr=0;
        int ans=INT_MIN;
        int n=s.size();
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                ctr++;
                ans=max(ans,ctr);
            }
            else if(s[i]==')'){
                ctr--;
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
        int ans = obj.maxDepth(s);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends