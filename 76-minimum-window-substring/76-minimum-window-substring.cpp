class Solution {
public:
    string minWindow(string s, string t) {
        
        int counter = t.size(), start=0, end=0;
        unordered_map<char,int>mp;
        int minLen = INT_MAX , minStart = 0;
        for(auto it : t)
            mp[it]++;
        
        while(end < s.size()){
            
            if(mp[s[end]] > 0)
                counter--;
            
            mp[s[end]]--;
            end++;
            
            while(counter == 0){
                
                if(end - start < minLen){
                    minLen = end - start;
                    minStart = start;
                }
                
                mp[s[start]]++;
                
                if(mp[s[start]] > 0)
                    counter++;
                
                start++;
            }
        }
        
        return minLen == INT_MAX ? "":s.substr(minStart, minLen);
    }
};