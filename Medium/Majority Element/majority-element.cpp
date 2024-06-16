//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        
        // your code here
        int ele;
        int ctr=0;
        int n=size;
        for(int i=0; i<n; i++){
            if(ctr==0){
                ele=a[i];
                ctr++;
            }
            else if(a[i]==ele) ctr++;
            else{
                ctr--;
            }
        }
        int count=0;
        for(int i=0; i<n; i++){
            if(a[i]==ele) count++;
        }
        if(count>n/2) return ele;
        return -1;
        
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends