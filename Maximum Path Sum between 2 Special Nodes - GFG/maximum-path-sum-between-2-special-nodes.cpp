//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

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
        if (i >= ip.size()) break;
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


class Solution {
public:

    int solve(Node* root, int &maxSum)
    {
        if(!root) return INT_MIN;
        if(!root->left  and !root->right) return root->data;
        
        int l = solve(root->left, maxSum);
        int r = solve(root->right, maxSum);
        
        // may be if there is only single leaf node so check 
        // Always take those paths which has 2 different leaf nodes
        if(root->left!=NULL && root->right!=NULL) 
            maxSum = max(maxSum, l+r+root->data);
        
        return max(l,r)+root->data;
    }
    
    int maxPathSum(Node* root)
    {
        int maxSum=INT_MIN;
        int temp = solve(root, maxSum);
        // Note: Here Leaf node is a node which is connected to exactly one different node.
        // Dry Run for this tree -> (9 N 8 2 1 3 1 4 6)
        if(root->left == NULL || root->right == NULL) 
            return max(temp, maxSum);
            
        return maxSum;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution ob;
        cout << ob.maxPathSum(root) << "\n";
    }
    return 0;
}
// } Driver Code Ends