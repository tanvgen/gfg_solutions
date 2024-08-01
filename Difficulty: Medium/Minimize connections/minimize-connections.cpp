//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        void dfs(int node, vector<vector<int>> &adj, vector<int> &vis){
            vis[node]=1;
            for(auto it:adj[node]){
                if(vis[it]==0){
                    dfs(it,adj,vis);
                }
            }
        }
        int minimumConnections(int n , vector<vector<int>> &connections)
        {
            // code here
            int edges=connections.size();
            if(n-1>edges) return -1;
            
            vector<vector<int>> adj(n);
            for(auto it:connections){
                int u=it[0];
                int v=it[1];
                
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            
            int ans=0;
            vector<int> vis(n,0);
            for(int i=0; i<n; i++){
                    if(!vis[i]){
                        ans++;
                        dfs(i,adj,vis);
                    }
            }
            return ans-1;
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int m;
        cin>>m;
        vector<vector<int>> connections(m,vector<int> (2));
        for(auto &j:connections)
            cin>>j[0]>>j[1];
        Solution s;
        cout<<s.minimumConnections(n,connections)<<endl;
    }
    return 0;
}
// } Driver Code Ends