//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int solve(int Arr[], int N, int x){
        int ans=0;
        sort(Arr, Arr+N);
        for(int i=0; i<N-2; i++){
            int j=i+1;
            int k=N-1;
            
            while(j<k){
                if(Arr[i]+Arr[j]+Arr[k]<=x){
                    ans+=k-j;
                    j++;
                }
                else k--;
            }
        }
        
        return ans;
    }
    int countTriplets(int Arr[], int N, int L, int R) {
        // code here
        return solve(Arr,N,R)-solve(Arr,N,L-1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int Arr[N];
        for (int i = 0; i < N; i++) cin >> Arr[i];
        int L, R;
        cin >> L >> R;
        Solution obj;
        cout << obj.countTriplets(Arr, N, L, R) << endl;
    }
    return 0;
}
// } Driver Code Ends