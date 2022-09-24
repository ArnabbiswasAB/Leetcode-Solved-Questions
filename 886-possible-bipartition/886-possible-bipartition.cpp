class Solution {
public:
    
    int checkBipartite(int i, vector<int> adj[], vector<int>& color){
        if(color[i] == -1) color[i] = 0;
        for(auto it : adj[i]){
            if(color[it] == -1){
                color[it] = 1 - color[i];
                if(!checkBipartite(it, adj, color)){
                    return false;
                }
            } else if(color[it] == color[i])
                return false;
        }
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        int m = dislikes.size();
        vector<int> adj[n+1];
        for(auto edge : dislikes){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> color(n+1, -1);
        for(int i = 0; i < n+1; i++){
            if(color[i] == -1){
                if(!checkBipartite(i, adj, color))
                    return false;
            }
        }
        return true;
    }
};