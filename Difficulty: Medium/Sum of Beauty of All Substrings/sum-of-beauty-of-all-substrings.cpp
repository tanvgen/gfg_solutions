//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // int beauty(string s){
    //     unordered_map<char,int> mp;
    //     for(int i=0; i<s.size(); i++){
    //         mp[s[i]]++;
    //     }
    //     int mini=INT_MAX;
    //     int maxi=INT_MIN;
    //     for(auto it: mp){
    //         if(it.second<mini){
    //             mini=it.second;
    //         }
    //         if(it.second>maxi){
    //             maxi=it.second;
    //         }
    //     }
    //     return maxi-mini;
    // }
    int beautySum(string s) {
        // Your code goes here
        int n=s.size();
        int ans=0;
        for(int i=0; i<n; i++){
            int mp[26]={0};
            for(int j=i; j<n; j++){
                int mini=INT_MAX;
                int maxi=INT_MIN;
                mp[s[j]-'a']++;
                for(int k=0; k<26; k++){
                    if(mp[k]>0){
                     maxi=max(maxi,mp[k]);
                     mini=min(mini,mp[k]);
                    }
                }
                ans+=(maxi-mini);
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
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends