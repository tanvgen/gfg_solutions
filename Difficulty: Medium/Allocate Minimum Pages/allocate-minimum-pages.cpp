//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to find minimum number of pages.
    long long max_students(int n, vector<int> &arr, int val){
        int ans=0;
        int max_pages=0;
        for(int i=0; i<n; i++){
            if(arr[i]+max_pages<=val){
                max_pages+=arr[i];
            }
            else{
                max_pages=arr[i];
                ans++;
            }
        }
        ans++;
        return ans;
    }
    long long findPages(vector<int> &arr, int m) {
        // code here
        int n=arr.size();
        if(n<m) return -1;
        long long low=*max_element(arr.begin(),arr.end());
        long long high=0;
        for(int i=0; i<n; i++){
            high+=arr[i];
        }
        while(low<=high){
            long long mid=(low+high)/2;
            if(max_students(n,arr,mid)<=m){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
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
    }
    return 0;
}
// } Driver Code Ends