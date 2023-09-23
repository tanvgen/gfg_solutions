//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        int ans;
        int a[n+2];
        for(int i=0; i<n+2; i++){
            a[i]=0;
        }
        for(int i=0; i<n; i++){
            if(arr[i]>0 && arr[i]<=n){
                a[arr[i]]++;
            }
        }
        for(int i=1; i<n+2; i++){
            if(a[i]==0){
                ans=i;
                break;
            }
        }
        return ans;
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends