class Solution {
public:
    int longestBeautifulSubstring(string s) {
        
        
        // aeiou
        int n = s.size(), ans = 0, distinct = 0;
        int low = 0, high = 1;
        while(high < n){
            
            if(s[high - 1] == 'a'){
                distinct = 1;
                low = high - 1;
                
                while(high<n && s[high - 1] <= s[high]){
                    if(s[high-1] < s[high])
                        distinct++;
                    
                    high++;
                }
                if(distinct == 5)
                    ans = max(ans, high - low);
            }
            
            high++;
        }
        
        
        return ans;
    }
};

 