//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class disjointSet{
    
    public :
       vector<int> parent, rank, size;
       
       disjointSet(int n){
           
           parent.resize(n+1);
           size.resize(n+1,1);
           rank.resize(n+1,0);
           
           for(int i=0; i<n; i++){
               parent[i] = i;
           }
       }
       
       
       int findParent(int node){
          if(node == parent[node])
          return node;
          
          return parent[node] = findParent(parent[node]);
       }
       
       
       void unionSize(int u,int v){
           
           int u_p = findParent(u);
           int v_p = findParent(v);
           
           if(u_p == v_p)
           return;
           
           if(size[u_p] < size[v_p]){
               parent[u_p] = v_p;
               size[v_p] += size[u_p];
           }
           else{
               parent[v_p] = u_p;
               size[u_p] += size[v_p];
           }
       }
       
       
       void unionRank(int u, int v){
           
           int u_p = findParent(u);
           int v_p = findParent(v);
           
           if(u_p == v_p)
           return;
           
           if(rank[u_p] < rank[v_p]){
               parent[u_p] = v_p;
           }
           else if(rank[v_p] < rank[u_p]){
               parent[v_p] = u_p;
           }
           else{
               parent[u_p] = v_p;
               rank[v_p]++;
           }
       }
};



class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        
           disjointSet ds(n * m);
        int vis[n][m];
        memset(vis, 0, sizeof vis);
        int cnt = 0;
        vector<int> ans;
        
        for(auto it : operators){
            
            int row = it[0];
            int col = it[1];
            
            if(vis[row][col] == 1){
                ans.push_back(cnt);
                continue;
            }
            
            vis[row][col] = 1;
            cnt++;
            
            int dr[] = {1,-1,0,0};
            int dc[] = {0,0,1,-1};
            
            for(int ind = 0; ind<4; ind++){
                
                int adjr = row + dr[ind];
                int adjc = col + dc[ind];
                
                if(adjr>=0 && adjr<n && adjc>=0 &&  adjc<m){
                    if(vis[adjr][adjc] == 1){
                        
                        int nodeno = row*m + col;
                        int adjno = adjr*m + adjc;
                        
                         if (ds.findParent(nodeno) != ds.findParent(adjno)) {
                            cnt--;
                            ds.unionSize(nodeno, adjno);
                        }
                    }
                }
            }
            
            ans.push_back(cnt);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends