//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int catchThieves(char arr[], int n, int k) 
    {
        // Code here
        vector<int> pol;
        vector<int> th;
        for(int i=0; i<n; i++){
            if(arr[i]=='P') pol.push_back(i);
            else th.push_back(i);
        }
        
        int i=0,j=0;
        int ans=0;
        while(i<pol.size() && j<th.size()){
            if(abs(pol[i]-th[j])<=k){
                ans++;
                i++;
                j++;
            }
            else if(pol[i]<th[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n >> k;
		char arr[n];
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
		Solution obj;
		cout<<obj.catchThieves(arr, n, k) << endl;
	}
	return 0; 
} 


// } Driver Code Ends