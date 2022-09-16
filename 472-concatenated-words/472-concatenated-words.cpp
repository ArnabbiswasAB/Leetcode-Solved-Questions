class Solution {
public:
    unordered_map<string,int>mp;
    int dfs(string s){
        
        if(!s.size())
            return 0;
        
        int ans = 0;
        for(int i=0; i<s.size(); i++){
            
            string word =  s.substr(0, i+1);
            
            if(mp.find(word) != mp.end())
                ans = max(ans, 1 + dfs(s.substr(i+1)));
        }
        
        return ans==0?-1:ans;
    }
    
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        for(auto x : words)
            mp[x]++;
        
        vector<string>ans;
        
        for(auto s : words){
            
            if(dfs(s) >= 2)
                ans.push_back(s);
        }
        
        return ans;
    }
};