//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
        // code here
        string ans(d,'0');
        
        if(s>9*d) return "-1";
        
        int i=d-1;
        while(s>9){
            ans[i]='9';
            i--;
            s-=9;
        }
        
        if(i>0){
            ans[i]=s-1+'0';
            ans[0]='1';
        }
        else{
            ans[0]=s+'0';
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends