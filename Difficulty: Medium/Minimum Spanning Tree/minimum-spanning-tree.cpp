//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        set<pair<int,int>> st;
        st.insert({0,0});
        vector<int> vis(V,0);
        int sum=0;
        while(st.size()>0){
            auto it=*st.begin();
            st.erase(it);
            int wt=it.first;
            int node=it.second;
            //int to=it.second.first;
            if(vis[node]==0){
                vis[node]=1;
                sum+=wt;
            
            for(auto i:adj[node]){
                int child=i[0];
                int w=i[1];
                if(vis[child]==0) st.insert({w,child});
            }
            
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends