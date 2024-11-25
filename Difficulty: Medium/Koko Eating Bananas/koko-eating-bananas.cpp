//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int N, vector<int>&piles, int hourlyrate){
        int ans=0;
        for(int i=0; i<N; i++){
            ans+=ceil(piles[i]/(double)hourlyrate);
        }
        return ans;
    }
    int kokoEat(vector<int>& piles, int H) {
        // Code here
        int N=piles.size();
        int high=*max_element(piles.begin(),piles.end());
        int low=1;
        int ans;
        while(low<=high){
            int mid=(low+high)/2;
            int ctr=solve(N,piles,mid);
            ans=mid;
            if(ctr>H){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;

        cout << ob.kokoEat(arr, k);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends