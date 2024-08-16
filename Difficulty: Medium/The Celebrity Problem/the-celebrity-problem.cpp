//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
 
class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    //this wont work, 2 arrays hi banani padegi
    int celebrity(vector<vector<int> >& mat) {
       int n=mat.size();
       int top=0, down=n-1;
       
       while(top<down){
           if(mat[top][down]==1){
               top++;
           }
           else if(mat[down][top]==1){
               down--;
           }
           else{
               top++;
               down--;
           }
       }
       
       for(int i=0; i<n; i++){
           if(i!=top){
               if(mat[top][i]!=0 || mat[i][top]==0){
                   return -1;
               }
           }
       }
       return top;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends