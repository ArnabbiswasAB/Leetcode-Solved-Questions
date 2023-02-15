//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DisjointSet{
    public: 
    
    vector<int>par;
    vector<int>size;

    DisjointSet(int n){
        par.resize(n+1);
        size.resize(n+1,1);

        for(int i=0;i<=n;i++){
            par[i] = i;
        }
    }

    int findpar(int u){
        if(u == par[u]){
            return u;
        }

        return par[u] = findpar(par[u]);
    }

    void unionSize(int u,int v){
        u = findpar(u);
        v = findpar(v);

        if(u == v) return;

        if(size[u] < size[v]){
            par[u] = v;
            size[v] += size[u];
        }
        else{
            par[v] = u;
            size[u] += size[v]; 
        }
    }
};

class Solution {
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        
        int n = grid.size();
        DisjointSet ds(n*n);
        
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,-1,1};
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                
                if(grid[i][j] == 0)
                continue;
                
                for(int ind = 0; ind<4; ind++){
                    
                    int row = i + dx[ind];
                    int col = j + dy[ind];
                    
                    if(row>=0 && col>=0 && row<n && col<n && grid[row][col] == 1){
                        int nodeNo = i*n + j;
                        int adjNo = row*n + col;
                        
                        ds.unionSize(nodeNo, adjNo);
                    }
                }
            }
        }
        
        int maxi = 0;
       
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                
                if(grid[i][j] == 1)
                continue;
                
                 set<int>st;
                 
                 for(int ind=0; ind<4; ind++){
                     int row = i + dx[ind];
                     int col = j + dy[ind];
                     
                     if(row>=0 && col>=0 && row<n && col<n && grid[row][col] == 1){
                         st.insert(ds.findpar(row*n + col));
                     }
                 }
                 
                 int total = 0;
                 
                 for(auto it : st){
                     total += ds.size[it];
                 }
                 
                 maxi = max(maxi, total + 1);
            }
        }
        
       maxi = max(maxi, ds.size[ds.findpar(0)]); 
        return maxi;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends