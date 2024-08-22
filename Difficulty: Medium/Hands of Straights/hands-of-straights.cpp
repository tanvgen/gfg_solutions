//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        // code here
        if(N%groupSize!=0){
            return false;
        }
        else{
            map<int,int> mp;
            for(int i=0; i<N; i++){
                mp[hand[i]]++;
            }
            while(!mp.empty()){
                auto it=mp.begin();
                int curr=it->first;
                for(int i=0; i<groupSize; i++){
                    if(mp[curr+i]==0){
                        return false;
                    }
                    mp[curr+i]--;
                    if(mp[curr+i]==0) mp.erase(curr+i);
                }
                
            }
            return true;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends