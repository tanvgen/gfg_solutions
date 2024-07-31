//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int,int>> q;
        q.push({0,start});
        
        vector<int> dis(100000,1e9);
        dis[start]=0;
        
        if(start==end) return 0;
        
        while(!q.empty()){
            int steps=q.front().first;
            int curr=q.front().second;
            q.pop();
            
            for(auto i:arr){
                int final=(curr*i)%100000;
                if(dis[final]>steps+1){
                    dis[final]=steps+1;
                    if(final==end) return dis[final];
                    q.push({steps+1,final});
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
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends