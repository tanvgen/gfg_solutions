//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
// 	bool square(long long a){
// 	    for(long long i=0; i<a; i++){
// 	        if(i*i==a){
// 	            return 1;
// 	        }
// 	    }
// 	    return 0;
// 	}
	long double maximumProfit(int N, long long C, vector<long long> w, vector<long long> p){
	    // Code here.
	    vector<pair<long double,int>> v(N);
	    for(int i=0; i<N; i++){
	        int x=sqrt(w[i]);
	        
	        if(x*x!=w[i]){
	            long double x=((long double)p[i])/((long double)w[i]);
	            v.push_back({x,i});
	        }
	    }
	    
	    sort(v.rbegin(), v.rend());
	    long double ans=0;
	    long long ctr=0;
	    for(int i=0; i<v.size(); i++){
	        int idx=v[i].second;
	        if(ctr+w[idx]<=C){
	            ctr+=w[idx];
	            ans+=p[idx];    
	        }
	        else{
	            ans+=(C-ctr)*(v[i].first);
	            break;
	        }
	    }
	    return ans;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		long long C;
		cin >> n >> C;
		vector<long long > w(n), p(n);
		for(int i = 0; i < n; i++){
		    cin >> w[i] >> p[i];
		}
		Solution ob;
		long double ans = ob.maximumProfit(n, C, w, p);
		cout << fixed << setprecision(3) << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends