//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int characterReplacement(string s, int k) {
        // code here
        
         unordered_map<char, int>mp;
        int left = 0, max_occurance = 0, ans = 0;

        for(int i=0; i<s.length(); i++){
            
            mp[s[i]]++;
            
            max_occurance = max(max_occurance, mp[s[i]]);
            
            if(i - left + 1 - max_occurance > k){
                mp[s[left]]--;
                left++;
            }
            else{
                ans = max(ans, i - left + 1);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;

        Solution obj;
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends