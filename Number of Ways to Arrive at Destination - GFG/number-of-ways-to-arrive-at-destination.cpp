//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        int mod = 1e9 + 7;
        vector<pair<int,int>>adj[n];
        
        for(int i=0; i<roads.size(); i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        
        
        vector<int>dist(n,1e9);
        vector<int>ways(n,0);
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        dist[0] = 0;
        ways[0] = 1;
        
        while(!pq.empty()){
            
            int node = pq.top().second;
            int node_dis = pq.top().first;
            pq.pop();
            
            for(auto it : adj[node]){
                
                if(node_dis + it.second < dist[it.first]){
                    dist[it.first] = node_dis + it.second;
                    pq.push({dist[it.first],it.first});
                    ways[it.first] = ways[node];
                }
                else if(node_dis + it.second == dist[it.first]){
                    ways[it.first] = (ways[it.first] + ways[node])%mod;
                }
            }
        }
        
        
        return ways[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends