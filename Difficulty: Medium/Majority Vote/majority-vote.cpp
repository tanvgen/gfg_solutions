//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        // Your code goes here.
        int ctr1=0,ctr2=0;
        int maj1=-1,maj2=-1;
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(ctr1==0 && nums[i]!=maj2){
                maj1=nums[i];
                ctr1=1;
            }
            else if(ctr2==0 && nums[i]!=maj1){
                maj2=nums[i];
                ctr2=1;
            }
            else if(nums[i]==maj1){
                ctr1++;
            }
            else if(nums[i]==maj2){
                ctr2++;
            }
            else{
                ctr1--;
                ctr2--;
            }
        }
        
        int ct1=0,ct2=0;
        
        for(int i=0; i<n; i++){
            if(nums[i]==maj1){
                ct1++;
            }
            else if(nums[i]==maj2){
                ct2++;
            }
        }
        
        vector<int> ans;
        if(ct1>n/3) ans.push_back(maj1);
        if(ct2>n/3) ans.push_back(maj2);
        
        if(ans.size()==0) return {-1};
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends