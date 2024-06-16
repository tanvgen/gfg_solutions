//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> findSubarray(int n, int a[]) {
        // code here
        int maxsum=INT_MIN;
        int sum=0;
        int ctr=0;
        int start=0,end=0, maxlen=0;
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(a[i]>=0) sum+=a[i];
            else {
                sum=0;
                ctr=i+1;
            }
            
            if(sum>maxsum){
                maxsum=sum;
                start=ctr;
                end=i;
                maxlen=(-start+end+1);
            }
            
            if(sum==maxsum && i-ctr+1>maxlen){
                start=ctr;
                end=i;
                maxlen=(-start+end+1);
            }
        }
        for(int i=start; i<=end; i++){
            ans.push_back(a[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(n, a);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends