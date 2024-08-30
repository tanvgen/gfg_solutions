//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:
    
    bool solve(unordered_set<string> &st, int i, int m, string &s, vector<int> &dp){
        if(i>=m) return true;
        if(dp[i]!=-1) return dp[i];
        
        if(st.find(s)!=st.end()) return true;
        
        for(int l=1; l<=m; l++){
            string temp=s.substr(i,l);
            if(st.find(temp)!=st.end() && solve(st,i+l,m,s,dp)){
                return dp[i]=true;
            }
        }
        return dp[i]=false;
    }
    int wordBreak(int n, string s, vector<string> &dictionary) {
        //code here
        unordered_set<string> st;
        for(int i=0; i<n; i++){
            st.insert(dictionary[i]);
        }
        int m=s.size();
        vector<int> dp(m+1,-1);
        return solve(st,0,m,s,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends