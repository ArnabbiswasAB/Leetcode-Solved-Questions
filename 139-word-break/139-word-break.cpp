class Solution {
public:
     set<string> vis;
    map<string, bool> mp;

    bool dfs(string s, int i, int n) {
        if (s.size() == 0) return mp[s] = true;
        if (mp.find(s) != mp.end()) return mp[s];
        for (int l = 1; l <= s.size(); l++) {
            string t = s.substr(0, l);
            // cout << t << " ";
            if (vis.find(t) != vis.end() and dfs(s.substr(l), i, n)) {
                // cout << t << " " ;
                return mp[t] = true;
            }
        }
        return mp[s] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
         int n = s.size();
        
        for (auto x : wordDict) {
            vis.insert(x);
        }
        // for(auto x:vis)
        //     cout << x << " " ;
        return dfs(s, 0, n);
    }
};