//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class DisjointSet{
    vector<int> size,parent;
  public:
    DisjointSet(int n){
      size.resize(n+1,1);
      parent.resize(n+1);
      for(int i=0; i<=n; i++){
          parent[i]=i;
      }
    }
    int findUPar(int node){
        if(parent[node]==node) return node;
        return parent[node]=findUPar(parent[node]);
    }
    void unionbysize(int u, int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
        int mxr=0;
        int mxc=0;
        for(auto it: stones){
            mxr=max(mxr,it[0]);
            mxc=max(mxc,it[1]);
        }
        
        DisjointSet ds(mxr+mxc+1);
        
        unordered_map<int,int> mp;
        for(auto it: stones){
            int row=it[0];
            int col=it[1]+1+mxr;
            ds.unionbysize(row,col);
            mp[row]=1;
            mp[col]=1;
        }
        
        int ctr=0;
        for(auto it:mp){
            if(ds.findUPar(it.first)==it.first){
                ctr++;
            }
        }
        return n-ctr;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends