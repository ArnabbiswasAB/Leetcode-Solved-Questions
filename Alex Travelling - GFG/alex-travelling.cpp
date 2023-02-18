//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        // code here
        
        vector<pair<int,int>>adj[n+1];
        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});
        vector<int>dist(n+1,1e9);
        dist[k] = 0;
        
        while(!pq.empty()){
            
            int node = pq.top().second;
            int cost = pq.top().first;
            pq.pop();
            
            
            for(auto it : adj[node]){
                
                if(dist[node] + it.second < dist[it.first]){
                    dist[it.first] = it.second + dist[node];
                    pq.push({dist[it.first], it.first});
                }
            }
        }
        
        
        int total = 0;
        for(int i=1; i<n+1; i++){
            if(dist[i] == 1e9)
            return -1;
            
            total = max(total, dist[i]);
        }
        
        return total;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends