//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    int minCost(vector<int>& arr) {
        int n=arr.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(auto it:arr) pq.push(it);
        
        int sum=0;
        
        while(pq.size()>1){
            auto first=pq.top(); pq.pop();
            auto second = pq.top(); pq.pop();
            
            sum+=(first+second);
            pq.push(first+second);
        }
        
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
    }
    return 0;
}

// } Driver Code Ends