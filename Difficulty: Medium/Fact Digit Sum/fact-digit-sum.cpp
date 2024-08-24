//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	vector<int> FactDigit(int N)
	{
	    // Code here
	    vector<int> fact(10,1);
	    for(int i=2; i<=9; i++){
	        fact[i]=fact[i-1]*(i);
	    }
	    int i=9;
	    string s;
	    vector<int> ans;
	    while(N>0 && i>0){
	        if(fact[i]<=N){
	            //cout<<i<<endl;
	            //s+=i+'0';
	            ans.push_back(i);
	            N-=fact[i];
	            //cout<<N<<endl;
	        }
	        else{
	            i--;
	            //cout<<i<<endl;
	        }
	    }
	    reverse(ans.begin(),ans.end());
	    //int ans=stoi(s);
	    //return {ans};
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.FactDigit(N);
		for(auto i: ans)
			cout << i;
		cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends