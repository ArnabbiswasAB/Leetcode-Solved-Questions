//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> eff(m, vector<int>(n, INT_MAX));
        
        priority_queue<pair<int,pair<int,int>>, vector< pair<int,pair<int,int>>>, greater< pair<int,pair<int,int>>>> pq;
        
        pq.push({0, {0,0}});
        eff[0][0] = 0;
        
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,-1,1};
        
        while(!pq.empty()){
            
            int coeff = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            
            
            if(i == m-1 && j == n-1)
            return coeff;
            
            for(int k=0; k<4; k++){
                
                int x = i + dx[k], y = j + dy[k];
                
                if(x>=0 && y>=0 && x<m && y<n){
                    
                    int cost = abs(grid[x][y] - grid[i][j]);
                    int new_ceff = max(coeff, cost);
                    
                    if(new_ceff < eff[x][y]){
                        eff[x][y] = new_ceff;
                        pq.push({new_ceff,{x,y}});
                    }
                }
            }
        }
        
        
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends