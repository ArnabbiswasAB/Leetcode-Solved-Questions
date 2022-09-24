class Solution {
public:
    void allPaths(vector<vector<int>>&graph, int src, int dest, vector<int>temp, vector<vector<int>> &ans){
        
        temp.push_back(src);
        
        if(src == dest)
        {
            ans.push_back(temp);
            return;
        }
        
        for(auto it : graph[src]){
            
          
            allPaths(graph, it, dest, temp, ans);
            
        }
        temp.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int>temp;
        
        allPaths(graph,0,n-1,temp,ans);
        return ans;
    }
};