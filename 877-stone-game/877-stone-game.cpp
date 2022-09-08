class Solution {
public:
    
   int dp[505][505];
    
    int func(int i,int j,vector<int> &v){
        if (i==j){
            return v[i];
        }
        if (i>j){
            return 0;
        }
        
        if (dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int a=v[i]+min(func(i+2,j,v),func(i+1,j-1,v));
        int b=v[j]+min(func(i,j-2,v),func(i+1,j-1,v));
     
     return dp[i][j]=max(a,b);
    }
    
    bool stoneGame(vector<int>& v) {
        int sum=0,i;
        for (i=0; i<v.size(); i++){
            sum+=v[i];
        }
        
        memset(dp,-1,sizeof(dp));
        
        return func(0,v.size()-1,v)>sum-func(0,v.size()-1,v);
    }
};