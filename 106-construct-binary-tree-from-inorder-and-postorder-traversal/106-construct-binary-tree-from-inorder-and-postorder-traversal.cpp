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

TreeNode* construct(vector<int>& postOrder, vector<int>& inOrder, int start, int end, int &index)
{
    
    if(start > end)
        return NULL;
    
    int ele = postOrder[index];
    int mid = mp[ele];
    index++;
    TreeNode* root = new TreeNode(ele);
    if(start == end)
        return root;
    
    root->right= construct(postOrder, inOrder, mid + 1, end,index);
    root->left= construct(postOrder, inOrder, start, mid - 1, index);
    return root;
}
    
    TreeNode* buildTree(vector<int>& inOrder, vector<int>& postOrder) {
        int n = inOrder.size();
    for(int i=0; i<n; i++)
        mp[inOrder[i]]=i;
    
    reverse(postOrder.begin(), postOrder.end());
    int index =0 ;   
    TreeNode* root = construct(postOrder,inOrder, 0, n-1 , index);
    return root;
    }
};