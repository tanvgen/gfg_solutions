//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    // your code here
    int open=0,close=0,ans=0;
    
    int n=s.size();
    if(n%2!=0) return -1;
    
    for(int i=0; i<n; i++){
        if(s[i]=='{'){
            open++;
        }
        else{
            if(open>0){
                open--;
            }
            else{
                close++;
            }
        }
    }
    ans=(close+1)/2+(open+1)/2;
    return ans;
}