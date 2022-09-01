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
    void counting(TreeNode* root, int &count, int prev){
        
        if(!root)
            return;
        
        if(root->val >= prev){
            prev= root->val;
            count++;
        }
       else if(root->val < prev && !root->left && !root->right)
           return;
           
        
        counting(root->left, count,prev);
        counting(root->right, count, prev);
        
        
    }
    
    int goodNodes(TreeNode* root) {
        
        if(!root->left && !root->right)
            return 1;
        
        int count = 0;
        counting(root, count, INT_MIN);
        return count;
    }
};