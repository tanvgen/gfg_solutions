//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int solve(int N, vector<int> p){
        // code here
        vector<int> degree(N);
        for(int i=1; i<N; i++){
            degree[i]++;
            degree[p[i]]++;
        }
        int ctr=0;
        for(int i=0; i<N; i++){
            if(degree[i]>1) ctr++;
        }
        if(ctr==0) return 0;
        return ctr-1;
    }
};


//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> p(N);
        for(int i = 0; i < N; i++){
            cin >> p[i];
        }

        Solution obj;
        cout << obj.solve(N, p) << "\n";
    }
}   
// } Driver Code Ends