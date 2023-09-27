//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>&vis, int &ct){
        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
        ct++;
        for(int i=-1; i<=1; i++){
            for(int j=-1; j<=1; j++){
                int nr=row+i;
                int nc=col+j;
                if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==1 && vis[nr][nc]==0){
                    dfs(nr,nc,grid,vis,ct);
                }
            }
        }
    }
    int findMaxArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    int ct=0;
                    dfs(i,j,grid,vis,ct);
                    ans=max(ans,ct);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends