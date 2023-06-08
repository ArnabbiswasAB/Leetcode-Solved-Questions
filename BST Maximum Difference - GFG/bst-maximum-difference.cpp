//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    Node* bhaiFind(Node* root, int t, int &s){
        if(root==NULL)return NULL;
        if(root->data>t){
            s+=root->data;
            bhaiFind(root->left,t,s);
        }
        else if(root->data==t)return root;
        else {
            s+=root->data;
            bhaiFind(root->right,t,s);
        }
    }
    void mj(Node* root,int &m,int p,int s,int t){
        if(root==NULL)return;
        if(root->left==NULL&&root->right==NULL){
            // cout<<p<<" ";
            if(root->data==t)m=s;
            else m=max(s-p-root->data,m);
            return;
        }
        if(root->data==t){
            mj(root->right,m,p,s,t);
            mj(root->left,m,p,s,t);
        }
        else{
             mj(root->right,m,p+root->data,s,t);
             mj(root->left,m,p+root->data,s,t);
        }
    }
    int maxDifferenceBST(Node *root,int t){
        // Code here
        if(root==NULL)return -1;
        int s=0;
        Node* target=bhaiFind(root,t,s);
        if(target==NULL)return -1;
        int m=INT_MIN;
        mj(target,m,0,s,t);
        // cout<<target->data<<" "<<s<<m;
        return m;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends