//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int binarySearchable(int Arr[], int n) {
        // code here
        vector<int> leftmax(n),rightmin(n);
        leftmax[0]=INT_MIN; rightmin[n-1]=INT_MAX;
        for(int i=1; i<n; i++){
            leftmax[i]=max(Arr[i-1],leftmax[i-1]);
        }
        for(int i=n-2; i>=0; i--){
            rightmin[i]=min(Arr[i+1],rightmin[i+1]);
        }
        int ans=0;
        
        for(int i=0; i<n; i++){
            if(leftmax[i]<Arr[i] && Arr[i]<rightmin[i]){
                ans++;
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
        int n;
        cin >> n;
        int Arr[n];
        for(int i=0;i<n;i++){
            cin >> Arr[i];
        }
        Solution obj;
        cout<<obj.binarySearchable(Arr,n)<<endl;
    }
    return 0;
}
// } Driver Code Ends