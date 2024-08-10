//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        int n=arr.size();
        int mini=10000;
        for(int i=0; i<n; i++){
            if(arr[i].size()<mini){
                mini=arr[i].size();
            }
        }
        //cout<<mini<<endl;
        string temp=arr[0].substr(0,mini);
        //cout<<temp<<endl;
        for(int i=1; i<n; i++){
            string temp1=arr[i];
            for(int j=0; j<mini; j++){
                //string temp2=arr[i+1];
                if(temp.size()==0) return "-1";
                if(temp[j]!=temp1[j]){
                    temp=temp.substr(0,j);
                    //temp.erase(temp.begin()+j);
                    //break;
                }
                
            }
            //break;
        }
        if(temp.size()>0) return temp;
        
        return "-1";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends