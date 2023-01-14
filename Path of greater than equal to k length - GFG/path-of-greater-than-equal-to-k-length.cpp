//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution {
public:
    typedef pair<int,int> pi;
    bool dfs(int i,vector<pi>adj[],vector<bool>&visited,int k,int cost)
    {
        visited[i] = 1;
        if(cost >= k)
            return 1;
        for(auto x:adj[i])
        {
            int v = x.first;
            int wt= x.second;
            if(!visited[v])
            {
                if(dfs(v,adj,visited,k,cost+wt))
                    return 1;
            }
        }
        visited[i] = 0;
        return 0;
        
    }
    bool pathMoreThanK(int V, int E, int k, int *a) 
    { 
       //  Code Here
       vector<pi>adj[V];
       for(int i=0;i<E*3;i=i+3)
       {
           int u =  a[i];
           int v =  a[i+1];
           int wt = a[i+2];
           //cout<<u<<" "<<v<<" "<<wt<<endl;
           adj[u].push_back({v,wt});
           adj[v].push_back({u,wt});
       }
       vector<bool>visited(V,0);
       return dfs(0,adj,visited,k,0);
    } 
};




//{ Driver Code Starts.


int main() {
	//code
    int t;cin >> t;
    while(t--)
    {
        int V, E, K;
        cin >> V >> E >> K;
        int a[3*E + 1];
        for(int  i=0;i<3*E;i++){
            cin >> a[i];
        }
        
        Solution obj;
        if(obj.pathMoreThanK(V, E, K, a)){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
        
    }
	return 0;
}
// } Driver Code Ends