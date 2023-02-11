//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubstring(string s) {
        // Code here
        unordered_map<char, int>mp;
        int i=0, j=0, count=0, n = s.length();
        
        while(j<n){
            
            mp[s[j]]++;
            
            while(mp.size() == 3){
                count += s.length() - j;
                
                mp[s[i]]--;
                if(mp[s[i]] == 0)
                mp.erase(s[i]);
                
                i++;
            }
            
            j++;
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution obj;
        cout << obj.countSubstring(s) << endl;
    }
    return 0;
}
// } Driver Code Ends