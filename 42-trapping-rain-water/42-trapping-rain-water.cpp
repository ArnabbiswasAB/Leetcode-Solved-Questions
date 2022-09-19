class Solution {
public:
    int trap(vector<int>& height) {
        
        int res=0;
        int n=height.size();
        
        int maxleft = INT_MIN, max_right = INT_MIN, left=0, right = n - 1;
        
        while(left<right){
            
            if(height[left]<=height[right]){
                
                if(height[left]>=maxleft)
                    maxleft=height[left];
                else
                    res += maxleft - height[left];
                
                left++;
            }
            else
            {
                if(height[right] >= max_right){
                    max_right=height[right];
                }
                else
                    res += max_right - height[right];
                
                right--;
            }
        }
        
        return res;
    }
};