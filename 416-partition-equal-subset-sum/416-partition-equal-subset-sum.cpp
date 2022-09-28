class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        
        int sum = 0;
        int n =nums.size();
        
        for(auto i : nums)
            sum += i;
        
       
        if(sum % 2 == 1)
            return false;
        else{
            sum /= 2;
            
            vector<bool>prev(sum+1,false);
            prev[0] = true;
            
            if(nums[0] <= sum)
                prev[nums[0]] = true;
            
            for(int i=1; i<n; i++){
                vector<bool>curr(sum+1,false);
                curr[0]=true;
                for(int j=1; j<=sum; j++){
                    
                    bool NotTaken = prev[j];
                    bool Taken = false;
                    
                    if(nums[i]<=j)
                        Taken = prev[j - nums[i]];
                    
                    curr[j] = NotTaken||Taken;
                }
                prev = curr;
            }
              return prev[sum];
        }
        
      
    }
};