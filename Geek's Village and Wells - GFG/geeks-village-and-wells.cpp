//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &c){
        // Code here
        
    vector<vector<int>> dp(n, vector<int>(m, 1e9));
    queue<pair<int,int>> q;
    
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                if(c[i][j] == 'N')
                dp[i][j] = -1;
                else if(c[i][j] == 'W'){
                dp[i][j] = 0;
                q.push({i,j});
                }
            }
        }
        
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        
        while(!q.empty()){
            
            auto it = q.front();
            q.pop();
            
            for(int i=0; i<4; i++){
                int x = dx[i] + it.first;
                int y = dy[i] + it.second;
                
                if(x<0 || y<0 || x>=n || y>=m)
                continue;
                
                if(dp[it.first][it.second] + 1 < dp[x][y]){
                    dp[x][y] = 1 + dp[it.first][it.second];
                    q.push({x,y});
                }
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                if(c[i][j] == '.')
                dp[i][j] = 0;
                else if(dp[i][j] == 1e9)
                dp[i][j] = -1;
                else if(dp[i][j] == -1)
                dp[i][j] = 0;
                else{
                    dp[i][j] *= 2;
                }
            }
        }
        
        return dp;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends