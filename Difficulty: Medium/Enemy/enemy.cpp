//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        int largestArea(int n,int m,int k,vector<vector<int>> &enemy)
        {
            //  code here
            vector<int> v1,v2;
            for(int i=0; i<k; i++){
                v1.push_back(enemy[i][0]);
                v2.push_back(enemy[i][1]);
            }
            
            sort(v1.begin(),v1.end());
            sort(v2.begin(),v2.end());
            
            int h=0,v=0;
            int ctr=0;
            for(auto it:v1){
                h=max(h,it-ctr-1);
                ctr=it;
            }
            h=max(h,n-ctr);
            ctr=0;
            for(auto it:v2){
                v=max(v,it-ctr-1);
                ctr=it;
            }
            v=max(v,m-ctr);
            
            return h*v;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int k;
        cin>>k;
        vector<vector<int>> e(k,vector<int>(2));
        for(int i=0;i<k;i++)
            cin>>e[i][0]>>e[i][1];
        Solution a;
        cout<<a.largestArea(n,m,k,e)<<endl;
    }
    return 0;
}
// } Driver Code Ends