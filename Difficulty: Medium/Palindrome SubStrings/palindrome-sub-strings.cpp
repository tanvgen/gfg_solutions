//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// User function Template for C++

class Solution {
  public:
    bool ispal(string &temp){
        int i=0,j=temp.size()-1;
        while(i<=j){
            if(temp[i]==temp[j]){
                i++;j--;
            }
            else{
                return 0;
            }
        }
        return 1;
    }
    int CountPS(char s[], int n) {
        // code here
        string str="";
        for(int i=0; i<n; i++) str+=s[i];
        
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                string temp=str.substr(i,j-i+1);
                if(ispal(temp)==1) {ans++;}
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
        int N;
        cin >> N;
        char S[N + 1];
        cin >> S;
        Solution ob;
        cout << ob.CountPS(S, N) << endl;
    }
    return 0;
}
// } Driver Code Ends