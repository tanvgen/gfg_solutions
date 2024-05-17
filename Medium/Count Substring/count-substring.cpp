//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubstring(string s) {
        // Code here
        int ctr1=-1, ctr2=-1, ctr3=-1;
        int n=s.size();
        int ans=0;
        
        for(int i=0; i<n; i++){
            if(s[i]=='a') ctr1=i;
            if(s[i]=='b') ctr2=i;
            if(s[i]=='c') ctr3=i;
            
            ans+=min(ctr1,min(ctr2,ctr3))+1;    
        
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
        cout << obj.countSubstring(s) << endl;
    }
    return 0;
}
// } Driver Code Ends