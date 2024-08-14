//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findMatching(string text, string pat) {
        // Code here
        int i=0,j=0;
        int start=0;//to store the required index
        int n=text.size();
        int m=pat.size();
        if(m>n) return -1;
        while(i<n && j<m){
            if(text[i]==pat[j]){
                if(i-start+1==m) return start;
                i++;
                j++;
            }
            else{
                j=0;
                start++;
                i=start;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string text, pat;
        cin >> text >> pat;
        Solution obj;
        cout << obj.findMatching(text, pat) << endl;
    }
    return 0;
}
// } Driver Code Ends