class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n = nums.size();
        int ans =0;
        if(n<3)
            return 0;
        
        int prev = nums[1] - nums[0];
        int ind = 0, diff = 0 ;
        
        for(int i=1; i<n-1; i++){
            
            diff = nums[i+1] - nums[i];
            
            if(diff == prev)
                ind++;
            else{
                 
                prev = diff;
                ind = 0;
            }
            
            ans += ind;
        }
        
        return ans;
    }
};