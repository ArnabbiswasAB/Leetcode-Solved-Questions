//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class DisjointSet{
    
    public :
    
    vector<int> rank, parent, size;
    
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        
        for(int i=0; i<=n ; i++){
            parent[i] = i;
            rank[i] = 1;
        }
    }
    
    int findParent(int node){
        
        if(parent[node] == node)
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
        else{
            parent[v_p] = u_p;
            rank[v_p]++;
        }
    }
    
    void UnionBySize(int u, int v){
        int u_p = findParent(u);
        int v_p = findParent(v);
        
        if(u_p == v_p)
        return;
        
        if(size[u_p] < size[v_p]){
            parent[u_p] = v_p;
            size[v_p] += size[u_p];
        }
        else {
            parent[v_p] = u_p;
            size[u_p] += size[v_p];
        }
    }
};


class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        
        
        DisjointSet ds(V);
        
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                
                if(adj[i][j] == 1)
                    ds.UnionBySize(i,j);
            }
        }
        
        
        int count = 0;
        
        
        for(int i=0; i<V; i++){
            
            if(ds.parent[i] == i)
            count++;
            
        }
        
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends