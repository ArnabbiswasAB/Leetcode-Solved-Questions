//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	   
	     int dx[] = {2,2,-2,-2,1,-1,1,-1};
         int dy[] = {1,-1,1,-1,2,2,-2,-2};
         
         vector<vector<int>> vis(N, vector<int>(N, 0));
         
          int x=KnightPos[0]-1;
          int y=KnightPos[1]-1;
    
          int tx=TargetPos[0]-1;
          int ty=TargetPos[1]-1;
    
          if(x==tx&&y==ty)
            return 0;
    
        queue<pair<int, pair<int,int>>>q;
        
        vis[x][y] = 1;
        q.push({0,{x,y}});
        
        while(!q.empty()){
            
            auto it = q.front();
            q.pop();
            
            int i = it.second.first, j = it.second.second;
            int dis = it.first;
            
            for(int k=0; k<8; k++){
                
                int x = dx[k] + i, y = dy[k] + j;
                
                if(x == tx && y == ty)
                return dis + 1;
                
                if(x<0 || y<0 || x>=N || y>=N || vis[x][y] != 0)
                continue;
                
                vis[x][y] = 1;
                q.push({dis+1, {x,y}});
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