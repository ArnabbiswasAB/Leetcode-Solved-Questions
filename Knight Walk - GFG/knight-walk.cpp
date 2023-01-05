//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int n){
	    // Code here
	    vector<vector<int>>vis(n, vector<int>(n,0));
	    
	    int x = KnightPos[0] - 1;
	    int y = KnightPos[1] - 1;
	    
	    int tx = TargetPos[0] - 1;
	    int ty = TargetPos[1] - 1;
	    
	    if(x == tx && y == ty)
	    return 0;
	    
	    int dx[] = {2,2,-2,-2,1,-1,1,-1};
       int dy[] = {1,-1,1,-1,2,2,-2,-2};
       
	    
	    queue<pair<int,pair<int,int>>> q;
	    q.push({0,{x,y}});
	    vis[x][y] = 1;
	    
	    while(!q.empty()){
	        
	        x = q.front().second.first;
	        y = q.front().second.second;
	        
	        int dist = q.front().first;
	        q.pop();
	        
	        
	        
	        for(int i=0; i<8; i++){
	            
	            int nx = x + dx[i];
	            int ny = y + dy[i];
	            
	            if(nx == tx && ny == ty)
	        return dist + 1;
	        
	            if(nx>=0 && ny>=0 && nx<n && ny<n && vis[nx][ny] == 0){
	                q.push({dist+1, {nx,ny}});
	                vis[nx][ny] = 1;
	            }
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
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends