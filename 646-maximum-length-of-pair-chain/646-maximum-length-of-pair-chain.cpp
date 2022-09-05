class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[0]==b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        
        int n = pairs.size();
        vector<int> dp(n,1);

        sort(pairs.begin(), pairs.end(), comp);
		
        for(int i=1; i<n; i++){
            int st = pairs[i][0];
            for(int j=0; j<i; j++){
                if(pairs[j][1] < st)
                    dp[i] = max(dp[i], 1+dp[j]);
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};