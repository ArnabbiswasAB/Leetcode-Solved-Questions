class Solution {
public:
    int mem(int idx, int allowance, vector<int>& days, vector<int>& cost, vector<vector<int>> &dp)
{
      // base case
    if(idx==days.size()) return 0;
    
    if(dp[idx][allowance]!=-1) return dp[idx][allowance];   // check condn
    
    // 3 choices :- either pick :- 1day, 7 days or 30 days allowance
    // pick
       int pick1 = cost[0] + mem(idx+1, days[idx] + 0, days, cost, dp);  // 1day
       int pick2 = cost[1] + mem(idx+1, days[idx]+7-1, days, cost, dp);  // 7days
       int pick3 = cost[2] + mem(idx+1, days[idx]+ 30-1, days, cost, dp); // 30days
        
    
    // notPick
    int np=INT_MAX;
    if(allowance>=days[idx])  np = mem(idx+1, allowance, days, cost, dp);
    
   return  dp[idx][allowance] = min(np, min(pick1, min(pick2, pick3))); // storing
}
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
         int n = days.size();
        int max_validity = days[n-1] + 30;
        vector<vector<int>> dp(n, vector<int>(max_validity, -1));
        return mem( 0, 0, days, costs, dp);
    }
};