class Solution {
public:
     int dp[13][10001];
     int findLowestCoins(vector<int> &coins, int i, int amount) 
    {
        if(i==0)
            return (amount%coins[0]==0) ? amount/coins[0] : 1e9;
        if(dp[i][amount]!=-1)
            return dp[i][amount];
        int doNotTakeCoin = 0 + findLowestCoins(coins, i-1, amount);
        int takeCoin = INT_MAX;
        if(coins[i] <= amount) 
            takeCoin = 1 + findLowestCoins(coins, i, amount-coins[i]);
        return dp[i][amount] = min(takeCoin, doNotTakeCoin);
    }
    int coinChange(vector<int> &coins, int amount) 
    {
        memset(dp, -1, sizeof(dp));
        int res = findLowestCoins(coins, coins.size()-1, amount);
        return (res >= 1e9) ? -1 : res;
    }
};