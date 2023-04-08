//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int minSteps(int m, int n, int d)
	{
	    // Code here
	    
	 vector<vector<int>> visited(m+1, vector<int> (n+1,0));
     queue<pair<int,int>> q;
     q.push({0,0});
     visited[0][0]=1;
     int steps=0;

     while(!q.empty())

     {

         int sz=q.size();

         while(sz--)

         {

             int x=q.front().first; // Water in jug 1
             int y=q.front().second; // water in jug 2
             q.pop();

             if(y==d || x==d) // Either of jug has required amount of water
                 return steps;
             
             if(x>0 && !visited[0][y]) // Empty jug 1
             {
                 q.push({0,y});
                 visited[0][y]=1;
             }

             if(y>0 && !visited[x][0]) // Empty jug 2
             {
                 q.push({x,0});
                 visited[x][0]=1;
             }

             if(x<m && !visited[m][y]) // Fill jug 1
             {
                 q.push({m,y});
                 visited[m][y]=1;
             }

             if(y<n && !visited[x][n]) // Fill jug 2
             {
                 q.push({x,n});
                 visited[x][n]=1;
             }

             if(m-x>0 && y>0) // Transfer water from jug 2 to jug 1
             {
                 if(x+y<m && !visited[x+y][0]) // Transfer all water from jug 2 to jug 1
                 {
                     q.push({x+y,0});
                     visited[x+y][0]=1;
                 }
                 else if(x+y>=m && !visited[m][y-(m-x)]) // Transfer some water from jug 2 to jug 1 with some left in jug 2
                 {
                     q.push({m,y-(m-x)});
                     visited[m][y-(m-x)]=1;
                 }
             }

             if(n-y>0 && x>0) // Transfer water from jug 1 to jug 2
             {
                 if(n-y>x && !visited[0][x+y]) // Transfer all water from jug 1 to jug 2
                 {
                     q.push({0,x+y});
                     visited[0][x+y]=1;
                 }
                 else if(x+y>=n && !visited[x-(n-y)][n]) // Transfer some water from jug 1 to jug 2 with some left in jug 1
                 {
                     q.push({x-(n-y),n});
                     visited[x-(n-y)][n]=1;
                 }
             }
             
         }
         steps++;
     }
     return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, d;
		cin >> m >> n >> d;
		Solution ob;
		int ans = ob.minSteps(m, n, d);
		cout << ans <<"\n";
	}  
	return 0;
}
// } Driver Code Ends