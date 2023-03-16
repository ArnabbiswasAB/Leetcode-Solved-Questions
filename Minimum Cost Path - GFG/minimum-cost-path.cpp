//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        
        int m = grid.size(), n = grid[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        
        vector<vector<int>> vis(m, vector<int>(n,0));
        int ans = 0;
        
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        
        vis[0][0] = 1;
        
        while(!pq.empty()){
            
            auto it=pq.top();
            int row=it.second.first;
            int col=it.second.second;
            int ans=it.first;
            
            pq.pop();
            
            ans = it.first;
            
            if(it.second.first == m-1 && it.second.second == n-1)
            return ans;
            
            for(int k=0; k<4; k++){
                
                int x = dx[k] + it.second.first;
                int y = dy[k] + it.second.second;
                
                if(x<0 || y<0 || x>=m || y>=n || vis[x][y] == 1)
                continue;
                
                pq.push({ans + grid[x][y],{x,y}});
                vis[x][y] = 1;
            }
        }
        
        return -1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends