class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
     
        int j=0, num = 0, ans = 0;
        
        for(int i=0; i<nums.size(); i++){
            
            while((num & nums[i]) != 0){
                num ^= nums[j];
                j++;
            }
            
            num |= nums[i];
            
            ans = max(ans, i - j + 1);
            
        }
        return ans;
    }
};