//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int canReach(int A[], int N) {
       int maxidxreached=0;
       for(int i=0; i<N; i++){
           if(i>maxidxreached) return 0;
           if(maxidxreached>=N) return 1;
           maxidxreached=max(maxidxreached,i+A[i]);
           
       }
       return 1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}
// } Driver Code Ends