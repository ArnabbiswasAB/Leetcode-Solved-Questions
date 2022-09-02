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
    unordered_map<int, int> val_to_idx;
    
    TreeNode* build(vector<int>& preorder, vector<int>& postorder, int pre_start, int post_start, int post_end){
        if(post_start > post_end) return NULL;
        if(post_start == post_end) return new TreeNode(preorder[pre_start]);
        
        int val = preorder[pre_start];
        int left_child = preorder[pre_start + 1];
        int left_child_idx = val_to_idx[left_child];
        int left_size = left_child_idx - post_start + 1;
        
        TreeNode* root = new TreeNode(val);
        root->left = build(preorder, postorder, pre_start+1, post_start, left_child_idx);
        root->right = build(preorder, postorder, pre_start+left_size+1, left_child_idx+1, post_end-1);
        
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for(int i = 0; i < postorder.size(); i++){
            val_to_idx[postorder[i]] = i;
        }
        return build(preorder, postorder, 0, 0, preorder.size()-1);
    }
};