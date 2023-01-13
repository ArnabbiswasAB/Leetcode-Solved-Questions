//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet{
    public:
    vector<int>rank,parent,size;
    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }

    int findPar(int node){
        if(node == parent[node])
        return node;

        return parent[node] = findPar(parent[node]);
    }

    void UnionRank(int u, int v){
        int u_p = findPar(u);
        int v_p = findPar(v);

        if(u_p == v_p)
        return ;

        if(rank[u_p] < rank[v_p]){
            parent[u_p] = v_p;
        }
        else if(rank[v_p] < rank[u_p]){
            parent[v_p] = u_p;
        }else{
            parent[v_p] = u_p;
            rank[u_p]++;
        }
    }


    void UnionSize(int u, int v){
        int u_p = findPar(u);
        int v_p = findPar(v);

        if(u_p == v_p)
        return;

        if(size[u_p] < size[v_p]){
            parent[u_p] = v_p;
            size[v_p] += size[u_p];
        }else{
            parent[v_p] = u_p;
            size[u_p] += size[v_p];
        }
    }
};


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        vector<pair<int,pair<int,int>>> edges;
       for(int i=0; i<V; i++){
           
           for(auto it : adj[i]){
               int wt = it[1];
               int adjNode = it[0];
               int node = i;
               
               edges.push_back({wt,{node,adjNode}});
               
           }
       }
       
       DisjointSet ds(V);
       sort(edges.begin(),edges.end());
       int weight = 0;
       
       for(auto it : edges){
           int wt = it.first;
           int u = it.second.first;
           int v = it.second.second;
           
           if(ds.findPar(u) != ds.findPar(v)){
               weight += wt;
               ds.UnionRank(u,v);
           }
       }
       
       return weight;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends