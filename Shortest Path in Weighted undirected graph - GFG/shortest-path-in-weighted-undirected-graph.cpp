//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        
         vector<pair<int,int>>adj[n+1];
        
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        vector<int>dist(n+1,1e9);
        dist[1] = 0;
        queue<pair<int,int>>q;
        q.push({0,1});
        
        vector<int>ans, curr(n+1,-1);
        
        while(!q.empty()){
            
            int node = q.front().second;
            int wt = q.front().first;
            q.pop();
            
            for(auto it : adj[node]){
                if(wt + it.second < dist[it.first]){
                    curr[it.first] = node;
                    dist[it.first] = wt + it.second;
                    q.push({dist[it.first], it.first});
                }
            }
        }
        
        
        if(dist[n] == 1e9)
        return {-1};
        
      while(n != -1){
          ans.push_back(n);
          n = curr[n];
      }
        
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends