//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    
    bool detectCycle(vector<int> adj[], int src, vector<int>&vis,vector<int>&dfsVis){
        
        vis[src] = 1;
        dfsVis[src] = 1;
        
        for(auto it : adj[src]){
            
            if(vis[it] == -1){
                if(detectCycle(adj, it, vis, dfsVis))
                return true;
            }else if(dfsVis[it]){
                return true;
            }
        }
        
        dfsVis[src] = 0;
        return false;
    }
    
    
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    
	    vector<int>adj[N];
	    for(auto it : prerequisites){
	        adj[it.second].push_back(it.first);
	    }
	    
	    vector<int>dfsVis(N,-1), vis(N,-1);
	    
	    for(int i=0; i<N; i++){
	        
	        if(vis[i] == -1)
	        {
	            if(detectCycle(adj,i,vis,dfsVis))
	            return false;
	        }
	    }
	    
	    return true;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends