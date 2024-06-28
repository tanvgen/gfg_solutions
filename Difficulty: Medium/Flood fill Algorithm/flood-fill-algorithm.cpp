//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vis[sr][sc]=1;
        int color=image[sr][sc];
        if(newColor==color) return image;
        image[sr][sc]=newColor;
        vector<vector<int>> ans(n,vector<int>(m,0));
        ans=image;
        
        int dx[]={-1,0,0,1};
        int dy[]={0,-1,1,0};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            for(int i=0; i<4; i++){
                int nr=row+dx[i];
                int nc=col+dy[i];
                
                if(nr>=0 && nc>=0 && nr<n && nc<m && image[nr][nc]==color && !vis[nr][nc]){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                    ans[nr][nc]=newColor;
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
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends