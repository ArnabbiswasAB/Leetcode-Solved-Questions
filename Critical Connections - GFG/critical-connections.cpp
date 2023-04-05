//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
vector<vector<int>> bridges;
int timer = 0;

void dfs(int node,int parent,vector<int>adj[], vector<int>& tin,vector<int>& vis,vector<int>& low){
    
    vis[node] = 1;
    tin[node] = low[node] = timer;
    
    timer++;
    
    for(auto it : adj[node]){
        
        if(it == parent) 
        continue;
        
        if(!vis[it]){
            dfs(it,node,adj, tin, vis, low);
            low[node] = min(low[node],low[it]);
            
            if(low[it] > tin[node]){
              if(it < node)
              bridges.push_back({it,node});
              else
              bridges.push_back({node, it});
            }
              
        }else{
            low[node] = min(low[node], low[it]);
        }
    }
    
    
}


	vector<vector<int>>criticalConnections(int V, vector<int> adj[]){
	    // Code here
	    
	    vector<int>tin(V), vis(V,0), low(V);
	    dfs(0,-1,adj,tin,vis,low);
	    
	    sort(bridges.begin(), bridges.end());
	    return bridges;
	}
};

//{ Driver Code Starts.

int main(){
	int tc;
    cin >> tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}
// } Driver Code Ends