//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int mid, vector<int> &arr, int n){
        int ctr=0;
        int sum=0;
        for(int i=0; i<n; i++){
            if(sum+arr[i]<=mid){
                sum+=arr[i];
            }
            else{
                sum=arr[i];
                ctr++;
            }
        }
        ctr++;
        return ctr;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        if(k>n) return -1;
        long long low=*max_element(arr.begin(),arr.end());
        long long high=0;
        for(int i=0; i<n; i++){
            high+=arr[i];
        }
        while(low<=high){
            long long mid=(low+high)/2;
            if(solve(mid,arr,n)>k){
                low=mid+1;
            }
            else high=mid-1;
        }
        return low;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends