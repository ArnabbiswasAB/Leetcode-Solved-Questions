class Solution {
public:
    
    vector<string>ans;
    
    void wB(string word, string res, vector<string>& wordDict){
     
        if(word.size() == 0){
            ans.push_back(res);
            return;
        }
        
        for(int i=0; i<=word.size(); i++){
            
           string left = word.substr(0, i); // storing left part from remaining word
        // looking for word in dictionary
            
        if((count(wordDict.begin(), wordDict.end(), left)) != 0)
        {
            string right = word.substr(i, word.size());
            // when result is empty don't add " " while concatenation res and left part
            res.empty() ? wB(right, res + left, wordDict) : wB(right, res + " " + left, wordDict);
        }
    }
}        
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
         wB(s, "", wordDict);
    return ans;
    }
};