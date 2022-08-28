class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int maxhere = 0;
        int minhere = 0;
        
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int total = 0;
        
        for(int i=0; i<nums.size(); i++){

        total += nums[i];
            
        maxhere = max(maxhere + nums[i] , nums[i]);
        minhere = min(minhere + nums[i] , nums[i]);
            
        maxi = max(maxi, maxhere);
        mini = min(mini, minhere);
        }
        
        if(total == mini)
            return maxi;
        
        return max(maxi, total - mini);
    }
};