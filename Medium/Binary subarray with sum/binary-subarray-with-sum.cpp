//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    int solve(vector<int>& arr, int N, int target){
        int i=0,j=0,ans=0;
        int sum=0;
        if(target<0) return 0;
        while(j<N){
            sum+=arr[j];
            
            while(sum>target){
                sum-=arr[i];
                i++;
            }

            ans+=(j-i+1);    
            
            j++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& arr, int N, int target){
        // code here
        return solve(arr,N,target)-solve(arr,N,target-1);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int target; 
        cin >> target;
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin >> arr[i];
        Solution obj;
        cout<<obj.numberOfSubarrays(arr, N, target)<<endl;
    }
    return 0;
}
// } Driver Code Ends