//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool check(string s){
        string k=s;
        reverse(k.begin(),k.end());
        return k==s;
    }
    string longestPalindrome(string S){
        // code here
        int n=S.size();
        string ans;
        int maxi=INT_MIN;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                string k=S.substr(i,j-i+1);
                if(check(k)){
                    int m=k.size();
                    if(maxi<m){
                        maxi=m;
                        ans=k;
                    }
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends