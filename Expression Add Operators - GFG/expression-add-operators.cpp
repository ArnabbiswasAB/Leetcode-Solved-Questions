//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  vector<string>ans;
  
  void helper(string s,int target,int i,string curr,long long res_sofar,long long prev){
     
     if(i == s.length()){
         if(res_sofar == target){
             ans.push_back(curr);
         }
         
         return ;
     } 
     
     for(int j=i; j<s.length(); j++){
         
         if(j>i && s[i] == '0')
         break;
         
         string str = s.substr(i,j-i+1);
         long long num = stoll(str);
         
         if(i==0){
             helper(s,target,j+1,curr + str, num,num);
         }
         else {
             
             helper(s,target,j+1,curr + '+' + str,res_sofar + num, num);
             
             helper(s,target,j+1,curr + '-' + str, res_sofar - num, - num);
             
             helper(s,target,j+1,curr + '*' + str, res_sofar - prev + prev*num, prev*num);
         }
     }
  }
  
  
    vector<string> addOperators(string s, int target) {
        // code here
        
        helper(s,target,0,"",0,0);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int target;
        string S;
        cin >> S >> target;

        Solution obj;
        vector<string> ans = obj.addOperators(S, target);
        sort(ans.begin(), ans.end());
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends