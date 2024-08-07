//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        if (source.first == destination.first &&
            source.second == destination.second)
            return 0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{source.first,source.second}});
        dist[source.first][source.second]=0;
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int dis=it.first;
            int row=it.second.first;
            int col=it.second.second;
            
            for(int i=0; i<4; i++){
                int nr=row+dx[i];
                int nc=col+dy[i];
                
                if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==1 && dist[nr][nc]>dis+1){
                    dist[nr][nc]=dis+1;
                    
                    if(nr==destination.first && nc==destination.second) {return dist[nr][nc];}
                    q.push({dist[nr][nc],{nr,nc}});
                }
            }
        }
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends