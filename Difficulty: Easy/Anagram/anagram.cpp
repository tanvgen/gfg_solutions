//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b) {

        // Your code here
        unordered_map<char,int> mp;
        for(int i=0; i<a.size(); i++){
            mp[a[i]]++;
        }
        for(int i=0; i<b.size(); i++){
            mp[b[i]]--;
        }
        for(auto it:mp){
            if(it.second!=0) return 0;
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.isAnagram(c, d))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

// } Driver Code Ends