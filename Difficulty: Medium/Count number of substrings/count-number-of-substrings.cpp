//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long solve(string s, int k){
        vector<int> v(26,0);
        int i=0,j=0;
        long long ans=0;
        int n=s.size();
        int dist_cnt=0;
        
        while(j<n){
            if(v[s[j]-'a']==0) dist_cnt++;
            v[s[j]-'a']++;
            
            while(dist_cnt>k){
                v[s[i]-'a']--;
                if(v[s[i]-'a']==0){
                    dist_cnt--;
                }
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
    long long int substrCount (string s, int k) {
    	//code here.
    	return solve(s,k)-solve(s,k-1);
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends