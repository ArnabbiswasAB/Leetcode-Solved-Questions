//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int maxIntersections(vector<vector<int>> lines, int N) {
    
         int slines[N];
        int elines[N];
        
        for(int i=0;i<N;i++)
        {
            slines[i] = lines[i][0];
            elines[i] = lines[i][1];
        }
        
        sort(slines, slines + N);
        sort(elines, elines + N);
        
        int i=0;
        int j=0;
        int intersections=0;
        int finalAns=INT_MIN;
        
        while(i<N && j<N)
        {
            if(slines[i] <= elines[j])
            {
                intersections++;
                finalAns = max(finalAns, intersections);
                i++;
            }
            else
            {
                intersections--;
                j++;
            }
        }
        
        
        return finalAns;

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> mat(N, vector<int>(2));
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < N; i++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        cout << obj.maxIntersections(mat, N) << endl;
    }
}
// } Driver Code Ends