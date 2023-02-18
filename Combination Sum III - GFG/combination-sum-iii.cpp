//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  vector<vector<int>> ans;
    
    void backtrack(int target, int k, int start, int end, vector<int>& temp){
        
        if(target == 0 && temp.size() == k){
            ans.push_back(temp);
            return;
        }
        
        for(int i=start; i<=end; i++){
            
            temp.push_back(i);
            backtrack(target - i, k, i+1, end, temp);
            temp.pop_back();
        }
    }
    
    
    vector<vector<int>> combinationSum(int K, int N) {
        // code here
        
        
        vector<int>temp;
        
        backtrack(N,K,1,9,temp);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends