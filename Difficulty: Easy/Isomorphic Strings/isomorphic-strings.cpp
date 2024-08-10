//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
        int n=str1.size();
        int m=str2.size();
        if(n!=m){
            return 0;
        }
        else{
            vector<int> v(26,-1);
            vector<int> v2(26,-1);
            for(int i=0; i<n; i++){
                if(v[str1[i]-'a']==-1 && v2[str2[i]-'a']==-1){
                    v[str1[i]-'a']=str2[i]-'a';
                    v2[str2[i]-'a']=str1[i]-'a';
                }
                else{
                    if(v[str1[i]-'a']!=str2[i]-'a' || v2[str2[i]-'a']!=str1[i]-'a' ){
                        return 0;
                    }
                }
            }
           return 1; 
        }
        
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends