/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    unordered_map<int,int>mp;
    int idx = 0;
    
    TreeNode* solve(vector<int>inOrder, vector<int>preOrder, int low, int high){
     
        if(high < low)
            return NULL;
        
        int ele = preOrder[idx++];
        int mid = mp[ele];
        
        TreeNode* root = new TreeNode(ele);
        
        if(low == high)
            return root;
        
        root->left = solve(inOrder, preOrder, low, mid - 1);
        root->right = solve(inOrder, preOrder, mid + 1, high);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        vector<int>inorder = preorder;
        int n = preorder.size();
        
        sort(inorder.begin(), inorder.end());
        
        for(int i=0; i<inorder.size(); i++)
            mp[inorder[i]] = i;
        
        return solve(inorder, preorder, 0, n-1);
    }
};