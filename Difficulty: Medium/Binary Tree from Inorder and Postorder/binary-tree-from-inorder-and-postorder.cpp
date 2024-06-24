//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL)
        return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution {
  public:

    // Function to return a tree created from postorder and inoreder traversals.
    Node* solve(int in[], int post[], int instart, int inend, int poststart, int postend, map<int,int> &mp){
        if(instart>inend || poststart>postend) return NULL;
        Node* root= new Node(post[postend]);
        int inroot=mp[root->data];
        //mp[root->data].pop();
        int diff=inroot-instart;
        
        root->left=solve(in,post,instart,inroot-1,poststart, poststart+diff-1,mp);
        root->right=solve(in,post,inroot+1,inend,poststart+diff,postend-1,mp);
        
        return root;
    }    
    Node *buildTree(int n, int in[], int post[]) {
        // Your code here
        map<int,int> mp;
        for(int i=0; i<n; i++){
            mp[in[i]]=i;
        }
        return solve(in,post,0,n-1,0,n-1,mp);
    }
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++)
            cin >> in[i];
        for (int i = 0; i < n; i++)
            cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(n, in, post);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends