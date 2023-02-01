//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSquares(int N, int M, vector<vector<int>> &mat) {
        // code here
        
        
        int count = 0;
        
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                
                if(mat[i][j] == 1 && i!=0 && j!=0){
                mat[i][j] = min(mat[i-1][j], min(mat[i-1][j-1],mat[i][j-1])) + 1;
                }
                count += mat[i][j];
            }
        }
        
        return count;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;

        vector<vector<int>> matrix(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        cout << obj.countSquares(N, M, matrix) << endl;
    }
    return 0;
}
// } Driver Code Ends