class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        unordered_map<string,int> mpp;
        int res=0;
        for(auto word: words){
            string revWord= word;
                reverse(revWord.begin(),revWord.end());
            if(mpp.find(revWord)!=mpp.end()){
                mpp[revWord]--;
                res+=4;
                if(mpp[revWord]==0){
                    mpp.erase(revWord);
                }
            }
            else{
                mpp[word]++;
            }
        }
        for(auto m: mpp){  // find if there us any self palindrome string we can use
            string revWord=string(m.first.rbegin(),m.first.rend());
            if(revWord==m.first){
                res+=2;
                break;
            }
        }
        return res;
    
    }
};