//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> nsr(int n, vector<int> &arr){
        stack<pair<int,int>> st;
        vector<int> v;
        
        for(int i=n-1; i>=0; i--){
            if(st.empty()){
                v.push_back(n);
            }
            else if(!st.empty() && st.top().first<arr[i]){
                v.push_back(st.top().second);
            }
            else{
                while(!st.empty() && st.top().first>=arr[i]){
                    st.pop();
                }
                if(st.size()==0){
                    v.push_back(n);
                }
                else{
                    v.push_back(st.top().second);
                }
            }
            st.push({arr[i],i});
        }
        reverse(v.begin(),v.end());
        return v;
    }
    vector<int> nsl(int n, vector<int> &arr){
        stack<pair<int,int>> st;
        vector<int> v;
        
        for(int i=0; i<n; i++){
            if(st.empty()){
                v.push_back(-1);
            }
            else if(!st.empty() && st.top().first<arr[i]){
                v.push_back(st.top().second);
            }
            else{
                while(!st.empty() && st.top().first>arr[i]){
                    st.pop();
                }
                if(st.size()==0){
                    v.push_back(-1);
                }
                else{
                    v.push_back(st.top().second);
                }
            }
            st.push({arr[i],i});
        }
        return v;
    }
    int sumSubarrayMins(int N, vector<int> &arr) {
        // code here
        int mod=1e9+7;
        long long sum=0;
        vector<int> v_nsl= nsl(N,arr);
        vector<int> v_nsr= nsr(N,arr);
        
        for(int i=0; i<N; i++){
            int left=i-v_nsl[i];
            int right=v_nsr[i]-i;
            sum=sum+(((arr[i]*left)%mod)*right)%mod;
        }
        return sum%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.sumSubarrayMins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends