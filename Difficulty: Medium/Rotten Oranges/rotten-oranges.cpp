//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        int count=0;
        queue<pair<pair<int,int>,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else{
                    if(grid[i][j]==1) count++;
                }
            }
        }
        
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        
        int ct=0;
        int t=0;    
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int timee=q.front().second;
            q.pop();
            t=max(t,timee);
            
            for(int i=0; i<4; i++){
                int nr=row+dx[i];
                int nc=col+dy[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==1 && !vis[nr][nc]){
                    ct++;
                    q.push({{nr,nc},timee+1});
                    vis[nr][nc]=2;
                }
            }
        }
        if(ct!=count) return -1;
        return t;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends