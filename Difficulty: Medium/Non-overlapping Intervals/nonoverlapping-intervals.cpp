//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minRemoval(int N, vector<vector<int>> &intervals) {
        // code here
        vector<pair<int,int>> v;
        for(int i=0; i<N; i++){
            v.push_back({intervals[i][1],intervals[i][0]});
        }
        sort(v.begin(),v.end());
        int ans=0;
        int ctr=v[0].first;
        for(int i=1; i<N; i++){
            if(v[i].second<ctr){
                ans++;
                //ctr=intervals[i-1][1]
            }
            else{
                ctr=v[i].first;
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

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(N, intervals) << endl;
    }
    return 0;
}
// } Driver Code Ends