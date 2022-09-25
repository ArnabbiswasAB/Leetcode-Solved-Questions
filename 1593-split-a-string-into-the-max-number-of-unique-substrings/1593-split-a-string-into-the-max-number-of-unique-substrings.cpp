class Solution {
public:
    int ans = 0;
    void backtracking(string s, int start, int n , set<string>&st){
        
        if(start == n){
            
            int res = st.size();
            ans = max(ans,res);
            return;
        }
        
        for(int i=start; i<n; i++){
            
            string left  = s.substr(start, i - start + 1);
            
            if(st.find(left) != st.end())
                continue;
            
            st.insert(left);
            backtracking(s, i+1, n, st);
            st.erase(left);
        }
    }
    
    
    int maxUniqueSplit(string s) {
        
        set<string>st;
        backtracking(s, 0, s.size(), st);
        return ans;
    }
};