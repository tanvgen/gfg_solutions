//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    long long solve(int X,int Y,string S){
      //code here
      int n=S.size();
      stack<char> st;
      long long ans=0;
      if(X>Y){
          //cout<<"ghvg"<<endl;
          for(int i=0; i<n; i++){
              char ch=S[i];
              if(!st.empty() && st.top()=='p' && ch=='r'){
                  st.pop();
                  ans+=X;
              }
              else{
                  st.push(ch);
              }
          }
          string s1;
          while(!st.empty()){
              s1.push_back(st.top());
              st.pop();
          }
          reverse(s1.begin(),s1.end());
          //cout<<S<<endl;
          for(int i=0; i<s1.size(); i++){
              char ch=s1[i];
              if(!st.empty() && st.top()=='r' && ch=='p'){
                  st.pop();
                  ans+=Y;
              }
              else{
                  st.push(ch);
              }
          }
      }
      else if(X<=Y){
          //cout<<"dxffcg"<<endl;
          for(int i=0; i<S.size(); i++){
              char ch=S[i];
              if(!st.empty() && st.top()=='r' && ch=='p'){
                  st.pop();
                  ans+=Y;
              }
              else{
                  st.push(ch);
              }
          }
          string s1;
          while(!st.empty()){
              s1.push_back(st.top());
              st.pop();
          }
         
          reverse(s1.begin(),s1.end());
          for(int i=0; i<s1.size(); i++){
              char ch=s1[i];
              if(!st.empty() && st.top()=='p' && ch=='r'){
                  st.pop();
                  ans+=X;
              }
              else{
                  st.push(ch);
              }
          }
      }
      return ans;
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends