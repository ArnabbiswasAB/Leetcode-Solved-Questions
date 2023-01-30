//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
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
  
    int longestChain(int n, vector<string>& words) {
        // Code here
        sort(words.begin(),words.end(),cmp);
        vector<int>dp(n,1);
        
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                
                if(check(words[i],words[j])){
                    if(dp[i] < 1 + dp[j])
                     dp[i] = dp[j] + 1;
                }
            }
        }
        
        
        return *max_element(dp.begin(),dp.end());
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> words(N);
        for (int i = 0; i < N; i++) {
            cin >> words[i];
        }
        Solution obj;
        cout << obj.longestChain(N, words) << "\n";
    }
    return 0;
}
// } Driver Code Ends