//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int characterReplacement(string S, int K) {
        // code here
        int arr[26]={0};
        int n=S.size();
        int i=0,j=0,maxfreq=0;
        int ans=0;
        while(j<n){
            arr[S[j]-'A']++;
            maxfreq=max(maxfreq,arr[S[j]-'A']);
            
            while(j-i+1-maxfreq>K){
                arr[S[i]-'A']--;
                i++;
            }
           ans=max(ans,j-i+1);
           j++;
        }
        return ans;

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;

        Solution obj;
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends