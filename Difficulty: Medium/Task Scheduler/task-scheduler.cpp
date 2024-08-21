//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        // code here
        vector<int> v(26,0);
        for(auto it:tasks){
            v[it-'A']++;
        }
        sort(v.begin(),v.end());
        int maxi=v[25];
        int idl=(maxi-1)*K;
        
        for(int i=24; i>=0; i--){
            idl-=min(v[i],maxi-1);
        }
        //cout<<idl<<endl;
        return N+max(0,idl);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends