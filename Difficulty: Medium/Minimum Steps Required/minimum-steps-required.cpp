//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    // Write your code here.
    int n=str.size();
    
    vector<int> arr;
    int ctr0=0,ctr1=0;
    for(int i=1; i<n; i++){
        if(str[i]!=str[i-1] && str[i]=='b'){
            arr.push_back(0);
        }
        else if(str[i]!=str[i-1] && str[i]=='a'){
            arr.push_back(1);
        }
    }
    if((str[n-1]=='a' && arr.empty()) || (str[n-1]=='a' && arr.back()==1)){
        arr.push_back(0);
    }
    else if((str[n-1]=='b' && arr.empty()) || (str[n-1]=='b' && arr.back()==0)){
        arr.push_back(1);
    }
    
    for(int i=0; i<arr.size(); i++){
        if(arr[i]==0) ctr0++;
        else ctr1++;
    }
    
    int mini=min(ctr1,ctr0);
    return mini+1;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends