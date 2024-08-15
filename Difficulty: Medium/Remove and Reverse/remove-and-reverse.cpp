//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string S) {
        // code here
        string temp=S;
        int n=S.size();
        unordered_map<char,int> mp;
        for(auto it:S) mp[it]++;
        
        int i=0,j=n-1;
        bool direction=0;
        
        while(i<=j){
            if(direction==0){
                if(mp[temp[i]]==1) i++;
                else{
                    mp[temp[i]]--;
                    temp[i]='#';
                    i++;
                    direction=1;
                }
            }
            else if(direction==1){
                if(mp[temp[j]]==1) j--;
                else{
                    mp[temp[j]]--;
                    temp[j]='#';
                    j--;
                    direction=0;
                }
            }
        }
        string ans="";
        for(auto it:temp){
            if(it!='#') ans+=it;
        }
        if(direction==1) reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends