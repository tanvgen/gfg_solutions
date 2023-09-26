//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int> ans;
        int count=0;
        int top=0,right=0,bottom=r-1,left=c-1;
        while(count<r*c){
            for(int i=right; i<=left && count<r*c; i++){
                ans.push_back(matrix[top][i]);
                count++;
            }
            top++;
            for(int i=top; i<=bottom && count<r*c; i++){
                ans.push_back(matrix[i][left]);
                count++;
            }
            left--;
            for(int i=left; i>=right && count<r*c; i--){
                ans.push_back(matrix[bottom][i]);
                count++;
            }
            bottom--;
            for(int i=bottom; i>=top && count<r*c; i--){
                ans.push_back(matrix[i][right]);
                count++;
            }
            right++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends