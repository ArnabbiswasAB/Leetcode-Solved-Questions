//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

vector<int> findSpiral(Node *root);

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
    Node* root = newNode(stoi(ip[0]));

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
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);

        vector<int> vec = findSpiral(root);
        for(int x : vec)
        cout<<x<<" ";
        cout << endl;
    }
    return 0;
}



// } Driver Code Ends



//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
    //Your code here
    
    if(!root)
    return {};
    
    vector<int>ans;
    queue<Node*>q;
    bool flag = false;
    
    q.push(root);
    
    while(!q.empty()){
        
        int k = q.size();
        vector<int>order;
        
        for(int i=0; i<k; i++){
            
            Node* node = q.front();
            q.pop();
            
            order.push_back(node->data);
            
            if(node->left)
            q.push(node->left);
            
            if(node->right)
            q.push(node->right);
            
            
        }
        
        if(flag){
            for(int i=0; i<order.size(); i++){
                ans.push_back(order[i]);
            }
            
            flag = !flag;
        }else{
            for(int i=order.size()-1; i>=0; i--){
                ans.push_back(order[i]);
            }
            
            flag = !flag;
        }
        
    }
    
    return ans;
}
