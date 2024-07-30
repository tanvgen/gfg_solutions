//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        int mod=1e9+7;
        
        vector<pair<int,int>> adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        vector<long long> ways(n,0);
        ways[0]=1;
        set<pair<long long,long long>> st;
        vector<long long> timee(n,1e18);
        timee[0]=0;
        
        st.insert({0,0});
        
        while(st.size()>0){
            auto it=*st.begin();
            st.erase(it);
            long long ctr_time=it.first;
            long long node=it.second;
            
            for(auto i:adj[node]){
                long long child=i.first;
                long long time_child=i.second;
                
                if(timee[child]>time_child+ctr_time){
                    timee[child]=time_child+ctr_time;
                    ways[child]=ways[node];
                    st.insert({timee[child],child});
                }
                else if(timee[child]==time_child+ctr_time){
                    ways[child]=(ways[child]+ways[node])%mod;
                }
            }
        }

        return ways[n-1]%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends