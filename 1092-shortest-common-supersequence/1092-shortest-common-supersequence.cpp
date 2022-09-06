class Solution {
public:
   int lcs(string text1, string text2, int size1, int size2, vector<vector<int>>& dp) {
        
        for (int i = 0; i <= size1; i++) dp[i][0] = 0;
        for (int j = 0; j <= size2; j++) dp[0][j] = 0;
        
        for (int i = 1; i <= size1; i++) {
            for (int j = 1; j <= size2; j++) {
                if (text1[i-1] == text2[j-1]) 
                    dp[i][j] = dp[i-1][j-1] + 1;
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[size1][size2];
    }
    
    string shortestCommonSupersequence(string str1, string str2) {
        int size1 = str1.size();
        int size2 = str2.size();
        vector<vector<int>> dp(size1+1, vector<int>(size2+1));

        int commonLength = lcs(str1, str2, size1, size2, dp);
        int i = size1, j = size2;
        string superSequence = "";
        
        while(i > 0 && j > 0) {
            if(str1[i-1] == str2[j-1]){
                superSequence += str2[j-1];
                i--, j--;
            } else {
                if (dp[i-1][j] > dp[i][j-1]){
                    superSequence += str1[i-1];
                    i--;
                }
                else {
                    superSequence += str2[j-1];
                    j--;
                }
            }
        }
        
        if ( i > 0){
            while (i > 0) {
                superSequence += str1[i-1];
                i--;
            }
        }
        
        if (j > 0) {
            while (j > 0) {
                superSequence += str2[j-1];
                j--;
            }
        }        
        reverse(superSequence.begin(), superSequence.end());
        
        return superSequence;
    }
};