//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



float findMedian(struct Node* node);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));
 
   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

int main() {
  
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   //cout << t << endl;
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root = buildTree(s);

      // getline(cin, s);
       
        cout << findMedian(root) << endl;

      // cout<<"~"<<endl;
   }
   return 0;
}
// } Driver Code Ends


/*
Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// your task is to complete the Function
// Function should return median of the BST
 void inorder(Node*root,vector<int>&in){
      if(root==NULL) return ;
      inorder(root->left,in);
      in.push_back(root->data);
      inorder(root->right,in);
  }
  
float findMedian(struct Node *root)
{   vector<int>in;
    inorder(root,in);
    int n=in.size();
    if(in.size()%2==1) return in[n/2] ; 
      else {
          return (in[(n-1)/2]+in[(n+1)/2])/2.0;
      }
    }
 
 
 /*
 
 /////time complexity: o(n)
/////space complexity: o(1)

int count(struct Node *root)
{
    if(root==0)
    return 0;
    return 1+count(root->left)+count(root->right);
}

int pre,curr;

void fun(Node* root,int &k)
{
    if(root==0)
    return ;
    
    fun(root->left,k);
    k--;
    
    if(k==1)
    {
      pre=root->data;
   
    }
    if(k==0)
    {
        curr=root->data;
     
    }
    
    fun(root->right,k);
}
float findMedian(struct Node *root)
{
      int n=count(root);
      if(n==1)
      return root->data;
      
      pre=-1,curr=-1;
      int k=n/2+1;
      fun(root,k);
      
      if(pre==-1||curr==-1)
      return -1;
      
      if(n%2==0)
      return (pre+curr)/2.0;
      return curr;
}
 
 */

