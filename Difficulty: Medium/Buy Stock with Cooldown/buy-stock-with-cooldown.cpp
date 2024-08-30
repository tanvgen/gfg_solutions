//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
        long long buy=-prices[0],sell=0, cool=0;
        for(int i=1;i<n;i++){
            long long ncool=max(cool,sell);
            long long nbuy=max(buy,cool-prices[i]);
            long long nsell=max(buy+prices[i],sell);
            buy=nbuy;
            sell=nsell;
            cool=ncool;
        }
        return sell;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends