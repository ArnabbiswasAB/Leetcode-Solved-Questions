//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


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



class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edges) {
        // code here
        
         DisjointSet ds(n);
          int cntExtras = 0;

          for(auto it : edges){
              int u = it[0];
              int v = it[1];

              if(ds.findPar(u) == ds.findPar(v)){
                  cntExtras++;
              }else{
                  ds.UnionSize(u,v);
              }
          }

          int cnt = 0;
          for(int i=0; i<n; i++){
              if(i == ds.findPar(i))
              cnt++;
          }

          int ans = cnt - 1;
          if(cntExtras >= ans)
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