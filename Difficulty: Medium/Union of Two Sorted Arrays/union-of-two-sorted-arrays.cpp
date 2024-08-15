//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        vector<int> ans;
        
        int i=0,j=0;
        while(i<n && j<m){
            if(arr1[i]==arr2[j]){
                if(ans.empty() || ans.back()!=arr1[i]){
                    ans.push_back(arr1[i]);
                }
                i++;
                j++; 
            }
            else if(arr1[i]<arr2[j]){
                if(ans.empty() || ans.back()!=arr1[i]){
                    ans.push_back(arr1[i]);
                }
                i++;
            }
            else if(arr1[i]>arr2[j]){
                if(ans.empty() || ans.back()!=arr2[j]){
                    ans.push_back(arr2[j]);
                }
                j++;
            }
        }

        for(int k=i; k<n; k++){
            if(ans.empty() || ans.back()!=arr1[k]) {ans.push_back(arr1[k]);}
        }
        for(int k=j; k<m; k++){
            if(ans.empty() || ans.back()!=arr2[k]) {ans.push_back(arr2[k]);}
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends