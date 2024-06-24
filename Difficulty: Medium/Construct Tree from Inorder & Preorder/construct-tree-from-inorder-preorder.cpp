//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    Node* solve(int in[], int pre[], int instart, int inend, int prestart, int preend, map<int,queue<int>> &mp){
        if(instart>inend|| prestart>preend) return NULL;
        Node* root= new Node(pre[prestart]);
        int inroot=mp[root->data].front();
        mp[root->data].pop();
        int diff=inroot-instart;
        
        root->left=solve(in,pre,instart,inroot-1, prestart+1, prestart+diff,mp);
        root->right=solve(in,pre,inroot+1,inend,prestart+1+diff,preend,mp);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        map<int,queue<int>> mp;
        for(int i=0; i<n; i++){
            mp[in[i]].push(i);
        }
        return solve(in,pre,0,n-1,0,n-1,mp);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends