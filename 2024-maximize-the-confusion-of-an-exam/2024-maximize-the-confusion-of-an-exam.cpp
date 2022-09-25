class Solution {
public:
    
    int findCon(string s, int k, char c){
        
        int left = 0, right = 0, n = s.size(), ans = 0;
        int zero = 0;
            
        while(right < n){
            
            if(s[right] == c)
                zero++;
            
            while(zero > k){
                
                if(s[left] == c)
                    zero--;
                
                left++;
            }
            
            ans = max(ans, right - left + 1);
            right++;
        }
        
        return ans;
    }
    
    int maxConsecutiveAnswers(string answerKey, int k) {
        
        return max(findCon(answerKey, k, 'T') , findCon(answerKey, k, 'F'));
    }
};