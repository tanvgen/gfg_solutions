//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void swapfunc(string &str, char x, char y){
        int n=str.size();
        for(int i=0; i<n; i++){
            if(str[i]==x){
                str[i]=y;
            }
            else if(str[i]==y){
                str[i]=x;
            }
        }
    }
    string chooseandswap(string str) {
        // Code Here
        int n=str.size();
        
        vector<int> mp(26,0);
        
        for(int i=0; i<n; i++){
            mp[str[i]-'a']=1;
        }
        // for(int i=0; i<26; i++){
        //     cout<<mp[i]<<endl;
        // }
        
        for(int i=0; i<n; i++){
            char ch=str[i];
            mp[ch-'a']=0;
            for(int j=0; j<ch-'a'; j++){
                if(mp[j]==1){
                    swapfunc(str,ch,j+'a');
                    return str;
                }
                
            }
            // mp[ch-'a']=0;
        }
        
        return str;
    }
};


//{ Driver Code Starts.

int main() {
    Solution obj;
    int t;
    cin >> t;
    while (t--) {
        string a;
        cin >> a;
        cout << obj.chooseandswap(a) << endl;
    }
    return 0;
}

// } Driver Code Ends