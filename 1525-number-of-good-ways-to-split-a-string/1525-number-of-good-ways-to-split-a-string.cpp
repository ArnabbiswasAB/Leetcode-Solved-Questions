class Solution {
public:
    int numSplits(string s) {
        
       vector<int>L(26,0);
       vector<int>R(26,0);
        
        int ans = 0; 
        int Uni_L = 0, Uni_R = 0;
        
        for(int i=0 ; i<s.size(); i++){
            
            L[s[i] - 'a']++;
            if(L[s[i] - 'a'] == 1)
                Uni_L++;
        }
        
        
        for(int i=0; i<s.size(); i++){
            
            R[s[i] - 'a']++;
            if(R[s[i] - 'a'] == 1)
                Uni_R++;
            
            L[s[i] - 'a']--;
            if(L[s[i] - 'a'] == 0)
                Uni_L--;
            
            if(Uni_L == Uni_R)
                ans++;
            else{
                if(ans != 0)
                    return ans;
            }
        }
        
        return ans;
    }
};