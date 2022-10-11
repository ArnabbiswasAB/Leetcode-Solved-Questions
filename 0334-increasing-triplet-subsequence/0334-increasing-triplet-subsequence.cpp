class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int firstNum=nums[0];
        int secondNum = INT_MAX;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>secondNum)
                return true;
            else if(nums[i]<firstNum)
                 firstNum=nums[i];
            else if(nums[i]>firstNum && nums[i]<secondNum)
                secondNum=nums[i];
        } 
        return false;
    }
};