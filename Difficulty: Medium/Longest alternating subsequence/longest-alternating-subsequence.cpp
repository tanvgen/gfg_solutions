//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int alternatingMaxLength(vector<int>& arr) {
        // Code here
        int n=arr.size();
        int flag=-1;
        int ans=1;
        for(int i=1; i<n; i++){
            if((flag==-1 ||flag==1) && arr[i]>arr[i-1]){
                flag=0;
                ans++;
            }
            else if((flag==-1 ||flag==0) && arr[i]<arr[i-1]){
                flag=1;
                ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }
        Solution obj;
        int ans = obj.alternatingMaxLength(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends