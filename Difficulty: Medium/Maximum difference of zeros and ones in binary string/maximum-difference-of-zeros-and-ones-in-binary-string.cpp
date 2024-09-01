//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S)
	{
	    // Your code goes here
	    int n=S.size();
	    
	    vector<int> arr(n);
	    int ct1=0;
	    for(int i=0; i<n; i++){
	        if(S[i]=='0') arr[i]=1;
	        else{ arr[i]=-1; ct1++; }
	    }
	    if(ct1==n) return -1;
	    //now the prob boils down to max sum subarray-kadane's algo
	    
	    int maxi=0,sum=0;
	    for(int i=0; i<n; i++){
	        sum+=arr[i];
	        if(sum<0) sum=0;
	        maxi=max(maxi,sum);
	    }
	    return maxi;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}

// } Driver Code Ends