//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        // Your code here
        vector<vector<int>> dis(n,vector<int>(n,1e9));
        
        for(int i=0; i<n; i++) dis[i][i]=0;
        
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            dis[u][v]=wt;
            dis[v][u]=wt;
        }
        
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
        
        vector<int> ct(n,0);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i!=j && dis[i][j]<=distanceThreshold){
                    ct[i]++;
                    ct[j]++;
                }
            }
        }
        int ans=0;
        for(int i=0; i<n; i++){
            if(ct[ans]>=ct[i]){
                ans=i;
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    
cout << "~" << "\n";
}
}

// } Driver Code Ends