//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  
  int helper(vector<int> & dp){
      
      stack<int>st;
      int area = 0, n = dp.size();
      
      for(int i=0; i<=n; i++){
          
          while(!st.empty() && (i == n || dp[st.top()] >= dp[i])){
              int height = dp[st.top()];
              st.pop();
              
              int width = 0;
              if(st.empty())
              width = i;
              else
              width = i - st.top() - 1;
              
              area = max(area, height * width);
          }
          
          st.push(i);
      }
      
      return area;
  }
  
  
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        
        vector<int>dp(m,0);
        int ans = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                if(M[i][j] == 0)
                   dp[j] = 0;
                else
                   dp[j]++;
                
            }
            
            ans = max(ans, helper(dp));
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends