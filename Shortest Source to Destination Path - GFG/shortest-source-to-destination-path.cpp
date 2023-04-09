//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        
        queue< pair<int , pair<int,int> >>q;
        if(A[0][0] == 0 || A[X][Y] == 0)
        return -1;
        
        q.push({0,{0,0}});
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        
        while(!q.empty()){
            
            auto it = q.front();
            q.pop();
           
            int dist = it.first;
            
            if(it.second.first == X && it.second.second == Y)
            return dist;
            
            
            for(int k=0; k<4; k++){
            
             int i = it.second.first + dx[k];
             int j = it.second.second + dy[k];
             
             if(i<0 || j<0 || i>=N || j>=M || A[i][j] == 0)
            continue;
            
                A[i][j] = 0;
                q.push({1+dist,{i,j}});
            }
        }
        
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends