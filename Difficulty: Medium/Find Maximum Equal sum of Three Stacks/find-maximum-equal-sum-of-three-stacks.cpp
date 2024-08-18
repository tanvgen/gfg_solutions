//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
        int sum1=0,sum2=0,sum3=0;
        for(int i=0; i<N1; i++){
            sum1+=S1[i];
        }
        for(int i=0; i<N2; i++){
            sum2+=S2[i];
        }
        for(int i=0; i<N3; i++){
            sum3+=S3[i];
        }
        int maxi=min(sum1,min(sum2,sum3));
        bool f1=0,f2=0,f3=0;
        int i=0,j=0,k=0;
        while(sum1>maxi || sum2>maxi || sum3>maxi){
            if(sum1>maxi){
            // if(sum1==maxi) f1=1;
            sum1-=S1[i];
            i++;
            //S1.erase(S1.begin());
            if(sum1<maxi){
                maxi=sum1;
            }
        }
            if(sum2>maxi){
            // if(sum2==maxi) f2=1;
            sum2-=S2[j];
            j++;
            //S2.erase(S2.begin());
            if(sum2<maxi){
                maxi=sum2;
            }
        }
        if(sum3>maxi){
            //if(sum3==maxi) f3=1;
            sum3-=S3[k];
            k++;
            //S3.erase(S3.begin());
            if(sum3<maxi){
                maxi=sum3;
            }
        }
        }
        if(sum1==maxi) f1=1;
        if(sum2==maxi) f2=1;
        if(sum3==maxi) f3=1;
        // while(sum1>maxi){
        //     // if(sum1==maxi) f1=1;
        //     sum1-=S1[0];
        //     S1.erase(S1.begin());
        //     if(sum1<maxi){
        //         maxi=sum1;
        //     }
        // }
        // if(sum1==maxi) f1=1;
        // while(sum2>maxi){
        //     // if(sum2==maxi) f2=1;
        //     sum2-=S2[0];
        //     S2.erase(S2.begin());
        //     if(sum2<maxi){
        //         maxi=sum2;
        //     }
        // }
        // if(sum2==maxi) f2=1;
        // while(sum3>maxi){
        //     //if(sum3==maxi) f3=1;
        //     sum3-=S3[0];
        //     S3.erase(S3.begin());
        //     if(sum1<maxi){
        //         maxi=sum3;
        //     }
        // }
        // if(sum3==maxi) f3=1;
        
        if(f1=1 && f2==1 && f3==1){
            return maxi;
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }
    
    return 0;
}
// } Driver Code Ends