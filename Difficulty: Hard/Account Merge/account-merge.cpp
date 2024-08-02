//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DisjointSet{
    vector<int> size,parent;
 public:
    DisjointSet(int n){
        parent.resize(n+1);
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
        size.resize(n+1,0);    
    }
    
    int findUPar(int node){
        if(parent[node]==node) return node;
        return parent[node]=findUPar(parent[node]);
    }
    
    void UnionbySize(int u, int v){
        int u_ulp=findUPar(u);
        int v_ulp=findUPar(v);
        if(parent[u]==parent[v]) return;
        if(size[u_ulp]> size[v_ulp]){
            parent[v_ulp]=u_ulp;
            size[u_ulp]+=size[v_ulp];
        }
        else{
            parent[u_ulp]=v_ulp;
            size[v_ulp]+=size[u_ulp];
        }
    }
};
class Solution {
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        // code here
        unordered_map<string,int> mp;
        int n=accounts.size();
        
        DisjointSet ds(n);
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                if(mp.find(accounts[i][j])!=mp.end()){
                    ds.UnionbySize(i,mp[accounts[i][j]]);
                }
                else{
                    mp[accounts[i][j]]=i;
                }
            }
        }
        
        vector<string> mergedmails[n];
        
        for(auto it: mp){
            string mail=it.first;
            int node=it.second;
            int ulp=ds.findUPar(node);
            mergedmails[ulp].push_back(mail);
        }
        vector<vector<string>> ans;
        
        for(int i=0; i<n; i++){
            if(mergedmails[i].size()!=0){
                string name=accounts[i][0];    
                sort(mergedmails[i].begin(), mergedmails[i].end());
                vector<string> temp;
                temp.push_back(name);
                for (auto it : mergedmails[i]) {
                    temp.push_back(it);
                }
                //temp.push_back(mergedmails[i]);
                ans.push_back(temp);
            }
            
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<string>> accounts;

        for (int i = 0; i < n; i++) {
            vector<string> temp;
            int x;
            cin >> x;

            for (int j = 0; j < x; j++) {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            accounts.push_back(temp);
        }

        ///
        Solution obj;
        vector<vector<string>> res = obj.accountsMerge(accounts);
        sort(res.begin(), res.end());
        cout << "[";
        for (int i = 0; i < res.size(); ++i) {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++) {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], " << endl;
            else
                cout << "]";
        }
        cout << "]" << endl;
    }
}
// } Driver Code Ends