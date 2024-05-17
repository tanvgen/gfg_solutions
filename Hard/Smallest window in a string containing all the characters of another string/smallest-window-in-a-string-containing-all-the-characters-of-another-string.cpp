//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        int n=p.size();
        vector<int> v(26,0);
        for(int i=0; i<n; i++){
            v[p[i]-'a']++;
        }
        int l=s.size();
        int i=0,j=0,ans=INT_MAX,ctr=0;
        int startidx=-1;
        while(j<l){
            if(v[s[j]-'a']>0){
                ctr++;
            }
            v[s[j]-'a']--;
            while(ctr==n){
                if(j-i+1<ans){
                    ans=j-i+1;
                    startidx=i;
                }
                v[s[i]-'a']++;
                if(v[s[i]-'a']>0){
                    ctr--;
                }
                i++;
            }
            
            j++;
        }
        if(ans==INT_MAX){
            return "-1";
        }
        else{
            return s.substr(startidx,ans);
        }
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends