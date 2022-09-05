 /*
    Explanation
Sort the words by word's length. (also can apply bucket sort)
For each word, loop on all possible previous word with 1 letter missing.
If we have seen this previous word, update the longest chain for the current word.
Finally return the longest word chain.


Complexity
Time O(NlogN) for sorting,
Time O(NSS) for the for loop, where the second S refers to the string generation and S <= 16.
Space O(NS)
    
    
    */
    
/*
words = ["a","b","ba","bca","bda","bdca"]

1. word = "a", prev = "", dp = {"a": 1}; It means that ending with "a", the max size of chain is 1.
2. word = "b", prev = "", dp = {"a": 1, "b": 1}; It means that ending with "b", the max size of chain is 1.
3. word = "ba", prev = "a" or "b", dp = {"a": 1, "b": 1, "ba": 2}; It means that ending with "ba", the max size of chain is 2.
	Here, both "a" and "b" can be the predecessor. We are interested only in length not the actual chain!
4. word = "bca", prev = "ba", dp = {"a": 1, "b": 1, "ba": 2, "bca":3}; It means that ending with "bca", the max size of chain is 3.
5. word = "bda", prev = "ba", dp = {"a": 1, "b": 1, "ba": 2, "bca":3, "bda": 3}; It means that ending with "bda", the max size of chain is 3.
6. word = "bdca", prev = "bda" or "bca", dp = {"a": 1, "b": 1, "ba": 2, "bca":3, "bda": 3, "bdca": 4}; It means that ending with "bdca", the max size of chain is 4.

*/
    
  class Solution {
public:
    
    /*
    Explanation
Sort the words by word's length. (also can apply bucket sort)
For each word, loop on all possible previous word with 1 letter missing.
If we have seen this previous word, update the longest chain for the current word.
Finally return the longest word chain.


Complexity
Time O(NlogN) for sorting,
Time O(NSS) for the for loop, where the second S refers to the string generation and S <= 16.
Space O(NS)
    
    
    */
    
    
    static bool cmp(string&s,string&t){
        if(s.length()==t.length()) return s<t;
        return s.length()<t.length();
    }
    bool check(string&s,string&t){
        if(s.length()!=t.length()+1) return false;
        int first=0,second=0;
        while(first<s.length()){
            if(s[first]==t[second]){
                first++;second++;
            }
            else{
                first++;
            }
        }
        if(first==s.length()&&second==t.length()) return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),cmp);
        vector<int>dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(words[i],words[j])) dp[i]=max(dp[i],1+dp[j]);
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};