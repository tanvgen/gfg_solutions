//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        
        for(int i=0; i<n; i++){
            if(grid[i][0]==1){
                vis[i][0]=1;
                q.push({i,0});
            }
            if(grid[i][m-1]==1){
                vis[i][m-1]=1;
                q.push({i,m-1});
            }
        }
        for(int i=0; i<m; i++){
            if(grid[0][i]==1){
                vis[0][i]=1;
                q.push({0,i});
            }
            if(grid[n-1][i]==1){
                vis[n-1][i]=1;
                q.push({n-1,i});
            }
        }
        
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            int dx[]={0,0,1,-1};
            int dy[]={1,-1,0,0};
            
            for(int i=0; i<4; i++){
                int nr=row+dx[i];
                int nc=col+dy[i];
                
                if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] && grid[nr][nc]==1){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]==0 && grid[i][j]==1){
                    ans++;
                }
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
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends