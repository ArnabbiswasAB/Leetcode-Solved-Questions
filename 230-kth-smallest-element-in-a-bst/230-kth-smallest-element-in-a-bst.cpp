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
   
    
   int helper(TreeNode* root, int* k){
        if(root->left){
            int x = helper(root->left, k);
            if(x != -1) return x;
        }
        (*k)--;
        if(*k == 0) return root->val;
        
        if(root->right){
            int x = helper(root->right, k);
            if(x != -1) return x;
        }
        
        return -1;
    }
    int kthSmallest(TreeNode* root, int k) {
        return helper(root, &k);
    }
};