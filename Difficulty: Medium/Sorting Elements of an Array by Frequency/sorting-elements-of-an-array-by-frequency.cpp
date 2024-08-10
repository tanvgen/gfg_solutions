#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int,int> a, pair<int,int> b){
    if(a.first==b.first){
        return a.second<b.second;
    }
    return a.first>b.first;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    map<int,int> mp;
	    for(int i=0; i<n; i++){
	        cin>>arr[i];
	        mp[arr[i]]++;
	    }
	    vector<int> ans;
	    vector<pair<int,int>> v;
	    for(auto it:mp){
	        v.push_back({it.second,it.first});
	    }
	    sort(v.begin(),v.end(),comp);
	    for(auto it:v){
	        int cnt=it.first;
	        int num=it.second;
	        for(int i=0; i<cnt; i++){
	            ans.push_back(num);
	        }
	    }
	    
	    for(auto it:ans){
	        cout<<it<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}