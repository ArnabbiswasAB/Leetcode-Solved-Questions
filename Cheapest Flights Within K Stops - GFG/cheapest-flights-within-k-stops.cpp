//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        
        queue<pair<int, pair<int,int>>> q;
        vector<pair<int,int>>adj[n];
        
        for(auto it : flights){
            int src = it[0];
            int dest = it[1];
            int cost = it[2];
            
            adj[src].push_back({dest,cost});
        }
        
        q.push({0, {src, 0}});
        vector<int>dist(n,1e9);
        dist[src] = 0;
        
        while(!q.empty()){
            
            int distt = q.front().first;
			int prev = q.front().second.first;
			int stp = q.front().second.second;
			q.pop();
			
            for(auto it : adj[prev]){
               	int nextNode = it.first;
				int nextDist = it.second;
                
                if(distt + nextDist < dist[nextNode] && stp<=K){
                    dist[nextNode] = distt + nextDist;
                    q.push({dist[nextNode], {nextNode, stp + 1}});
                }
            }
            
        }
        
        if(dist[dst] == 1e9)
        return -1;
        
        return dist[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends