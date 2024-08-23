//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<pair<int,pair<int,int>>> v(n);
        for(int i=0; i<n; i++){
            v[i].first=arr[i].profit;
            v[i].second.first=arr[i].dead;
            v[i].second.second=arr[i].id;
        }
        sort(v.rbegin(),v.rend());
        int maxdeadline=0;
        for(int i=0; i<n; i++){
            maxdeadline=max(maxdeadline,arr[i].dead);
        }
        int num=0;
        int prof=0;
        vector<int> slots(maxdeadline+1,0);
        for(int i=0; i<n; i++){
            int deadline=v[i].second.first;
            for(int j=deadline; j>0; j--){
                if(slots[j]==0){
                    num++;
                    prof+=v[i].first;
                    slots[j]=1;
                    break;
                }
            }
            
        }
        
        return {num,prof};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends