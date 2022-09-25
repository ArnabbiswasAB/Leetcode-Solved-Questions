class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int i = 0, l = 0, ans = 0, n =nums.size();
        int zero = 0;    
        while(i<n){
            
           if(nums[i] == 0)
               zero++;
            
           while(zero > k){
               if(nums[l] == 0)
                   zero--;
               
               l++;
           } 
            
            ans = max(ans, i - l + 1);
            i++;
        }  
        
        return ans;
    }
};