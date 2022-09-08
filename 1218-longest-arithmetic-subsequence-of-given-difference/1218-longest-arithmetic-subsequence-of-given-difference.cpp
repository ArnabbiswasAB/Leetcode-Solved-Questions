class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        
        int n = arr.size();
       unordered_map<int, int> dp;
        int ans = 1;
        for(int i = 0 ; i < arr.size() ; i++){
            int prevApElement = arr[i] - difference;
            dp[arr[i]] = 1 + dp[prevApElement];
            ans = max(dp[arr[i]], ans);
        }
        return ans;
    }
};