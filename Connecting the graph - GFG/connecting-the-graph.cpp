//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class disjointSet{
    
    public :
    vector<int>rank,parent,size;
    
    disjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }
    
    int findPar(int node){
        if(parent[node] == node)
        return node;
        
        return parent[node] = findPar(parent[node]);
    }
    
    void unionSize(int u, int v){
        
        int u_p = findPar(u);
        int v_p = findPar(v);
        
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
        
        int u_p = findPar(u);
        int v_p = findPar(v);
        
        if(u_p == v_p)
        return;
        
        if(rank[u_p] < rank[v_p]){
            parent[u_p] = v_p;
        }
        else if(rank[v_p] < rank[u_p]){
            parent[v_p] = u_p;
        }
        else{
            parent[v_p] = u_p;
            rank[u_p]++;
        }
    }
    
};


class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        
        int extra = 0;
        disjointSet ds(n);
        
        for(auto it : edge){
           
           int u = it[0], v = it[1];
           
           if(ds.findPar(u) == ds.findPar(v)){
               extra++;
           }
           else{
               ds.unionSize(u,v);
           }
        }
        
        int count = 0;
        for(int i=0; i<n; i++){
            if(i == ds.findPar(i))
            count++;
        }
        
        int ans = count - 1;
        if(extra >= ans)
        return ans;
        
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends