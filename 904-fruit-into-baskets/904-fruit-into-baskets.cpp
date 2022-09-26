class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        unordered_map<int,int>mp;
        
        int n = fruits.size();
        int i=0, j=0, k=2, ans = 0;
        
            while(i<n){
                
                mp[fruits[i]]++;
                
                while(mp.size() > k){
                    
                    mp[fruits[j]]--;
                    if(mp[fruits[j]] == 0)
                        mp.erase(fruits[j]);
                    
                    j++;
                }
                
                ans = max(ans, i - j + 1);
                i++;
            }
        return ans;
    }
};