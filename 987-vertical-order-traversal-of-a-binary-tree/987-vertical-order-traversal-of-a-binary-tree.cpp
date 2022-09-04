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
bool compare(pair<int, int>p1, pair<int, int>p2)
{    
        if(p1.second == p2.second) // level equal means sort on the basis of data values
            return p1.first < p2.first; // on the basis of data values
        return p1.second < p2.second;  // on the basis of level (Normal => vertical Order) 
            
    }



class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        
        vector<vector<int>>ans;
        if (!root)
            return ans;
        // vector<pair<int, int>> => (node->data , level)
        map<int, vector<pair<int, int>>>mp; // keys are sorted in map (horizontal distance sorted)
        int hd = 0;
        int level = 0;
        
        // Create queue to do "level order traversal".
        queue<pair<TreeNode*, pair<int, int>>>q;
        q.push({root, {hd, level}});
 
        while (!q.empty()) 
        {
            // pop from queue front
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            hd = p.second.first;
            level = p.second.second;
            
            // insert this node's data in vector of hash which are at same horizontal distance
            mp[hd].push_back({node->val, level}); // push(data, level)
            if (node->left != NULL)
                q.push({node->left, {hd - 1, level+1}});
            
            if (node->right != NULL)
                q.push({node->right, {hd + 1, level+1}});
        }
        
        for (auto x : mp) 
        {   
           if(x.second.size() > 1)
               sort(x.second.begin(), x.second.end(), compare);
            
           vector<int>temp; 
           for(auto p : x.second)
           {
                temp.push_back(p.first); //push only data       
           }
           ans.push_back(temp);
        }
        
        return ans;     
    }
};