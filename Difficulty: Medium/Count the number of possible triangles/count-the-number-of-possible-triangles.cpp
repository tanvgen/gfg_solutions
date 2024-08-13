//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to count the number of possible triangles.
    int findNumberOfTriangles(int arr[], int n)
    {
        // code here
        //(a+b)>c
        int ans=0;
        sort(arr,arr+n);
        for(int c=n-1; c>=2; c--){
            int a=0;
            int b=c-1;
            while(a<b){
                if(arr[a]+arr[b]>arr[c]){
                    ans+=(b-a);
                    b--;
                }    
                else{
                    a++;
                }
            }
            
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.findNumberOfTriangles(arr,n) <<endl;
    }
    return 0;
}
// } Driver Code Ends