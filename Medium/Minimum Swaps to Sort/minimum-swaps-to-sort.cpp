//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{   
	    int n=nums.size();
	    vector<int> arr=nums;
	    sort(nums.begin(), nums.end());
	    unordered_map<int,int> mp;
	    for(int i=0; i<n; i++){
	        mp[arr[i]]=i;
	    }
	    int ct=0;
	    for(int i=0; i<n; i++){
	        if(arr[i]!=nums[i]){
	            ct++;
	            int idx=mp[nums[i]];
	            mp[arr[i]]=idx;
	            swap(arr[i],arr[idx]);
	            //mp[arr]
	           // ct++;
	        }
	    }
	    return ct;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends