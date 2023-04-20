//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++


class Solution {
  public:
     void mapping(Node* root,int t,Node* &save,unordered_map<Node*,Node*> &mp){
         
         if(!root)
         return;
         
         queue<Node*>q;
         q.push(root);
         mp[root] = NULL;
         
         while(!q.empty()){
             
             Node* node = q.front();
             q.pop();
             
             if(node->data == t)
                save = node;
             
             
             if(node->left){
                 q.push(node->left);
                 mp[node->left] = node;
             }
             
             if(node->right){
                 q.push(node->right);
                 mp[node->right] = node;
             }
         }
         
         return;
     }
     
     
    int minTime(Node* root, int target) 
    {
        if(!root)
        return 0;
        
        unordered_map<Node*,Node*>mp;
        Node* save = NULL;
        mapping(root, target, save, mp);
        unordered_map<Node*, bool>vis;
        vector<int>ans;
        queue<Node*>q;
        int times = 0;
        q.push(save);
        vis[save] = 1;
        
        while(!q.empty()){
            
            int k = q.size();
            
            for(int i=0; i<k; i++){
                
                Node* node = q.front();
                q.pop();
                
                if(node->left && !vis[node->left]){
                    q.push(node->left);
                    vis[node->left] = true;
                }
                
                if(node->right && !vis[node->right]){
                    q.push(node->right);
                    vis[node->right] = true;
                }
                
                if(mp[node] && !vis[mp[node]]){
                    q.push(mp[node]);
                    vis[mp[node]] = 1;
                }
            }
            
            if(!q.empty())
            times++;
        }
        
        return times;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends