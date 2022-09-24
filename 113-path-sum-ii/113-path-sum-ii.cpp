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
      vector<vector<int>>anus;
    void calc(TreeNode *root,vector<int>tmp,int target)
    {
        if(root==nullptr)
            return;
        
       int sum1 = target - root->val;   
        
        tmp.push_back(root->val);
        calc(root->left,tmp, sum1);
        calc(root->right,tmp, sum1);
        
        if(sum1==0 && root->left==nullptr && root->right==nullptr)
        {
                anus.push_back(tmp);
        }
        
    }
    
    
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
         vector<int>tmp;
        calc(root,tmp,targetSum);
        return anus;
    }
};