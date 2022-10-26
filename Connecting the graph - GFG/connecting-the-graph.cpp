//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class disjointSet{
    public:
    
    vector<int> size,parent,rank;
    
    disjointSet(int n){
        size.resize(n+1);
        parent.resize(n+1);
        rank.resize(n+1,0);
        
        for(int i=0; i<=n; i++){
            parent[i] = i;
            size[i] = 1;
         }
    }
    
    int findParent(int node){
        
        if(node == parent[node])
        return node;
        
        return parent[node] = findParent(parent[node]);
    }
    
    
    void UnionByRank(int u, int v){
        
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
        else
        {
            parent[v_p] = u_p;
            rank[u_p]++;
        }
    }
    
    
    void UnionBySize(int u, int v){
        
        int u_p = findParent(u);
        int v_p = findParent(v);
        
        if(size[u_p] < size[v_p])
        {
            parent[u_p] = v_p;
            size[v_p] += size[u_p];
        }
        else{
            parent[v_p] = u_p;
            size[u_p] += size[v_p];
        }
    }
};


class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge){
        // code here
        
        disjointSet ds(n);
        int cnt = 0;
        
        for(auto it : edge){
            int u = it[0];
            int v = it[1];
            
            if(ds.findParent(u) == ds.findParent(v)){
                cnt++;
            }
            else{
                ds.UnionBySize(u,v);
            }
        }
        
        int countParent = 0;
        for(int i=0; i<n; i++){
            if(ds.parent[i] == i)
            countParent++;
        }
        
        int ans = countParent - 1;
        if(cnt >= ans)
        return ans;
        
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m; cin>>n>>m;
        vector<vector<int>>adj;
        
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
            
            Solution Obj;
            cout<<Obj.Solve(n,adj)<<"\n";
    }
    return 0;
}
// } Driver Code Ends