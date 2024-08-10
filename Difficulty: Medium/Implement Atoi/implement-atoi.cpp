//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int ans=0;
        int n=s.size();
        char ch;
        if(s[0]=='+' || s[0]=='-'){
            ch=s[0];
            string temp1;
            for(int i=1; i<n; i++){
                if(s[i]>='0' && s[i]<='9'){
                    temp1+=s[i];
                }
                else{
                    return -1;
                }
            }
            
            for(int i=temp1.size()-1; i>=0; i--){
               // cout<<s[i]-'0'<<endl;
                ans+=((temp1[i]-'0')*pow(10,temp1.size()-1-i));
                //cout<<ans<<endl;
            }
            if(ch=='-'){
                ans*=-1;
            }
        }
        
        else{
            string temp2;
            for(int i=0; i<n; i++){
                if(s[i]>='0' && s[i]<='9'){
                    temp2+=s[i];
                }
                else{
                    return -1;
                }
            }
            for(int i=temp2.size()-1; i>=0; i--){
                ans+=((temp2[i]-'0')*pow(10,temp2.size()-1-i));
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		int ans=ob.atoi(s);
		cout<<ans<<endl;
	}
}
// } Driver Code Ends