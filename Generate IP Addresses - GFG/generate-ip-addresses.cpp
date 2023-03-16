//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
 
    
   bool valid(string s){

        if(s.length() == 0 || s.length() > 3)
        return false;

        if(s.length() > 1 && s[0] == '0')
        return false;

        if(s.length() > 1 && stoi(s) > 255)
        return false;

        return true;
    }
    
    void helper(string s, string temp, int ind, int dots,  vector<string>& ans){
        
        if(dots == 3){
            if(valid(s.substr(ind))){
                ans.push_back(temp + s.substr(ind));
            }
            return;
        }

       int sz = s.length();
        for(int i=ind;i<min(ind+3, sz);i++){

            if(valid(s.substr(ind, i - ind + 1))){
                temp.push_back(s[i]);
                temp.push_back('.');
                helper(s, temp, i+1, dots+1, ans);
                temp.pop_back();
            }
        }
    }
    
    
    vector<string> genIp(string &s) {
        // Your code here
        string temp = "";
        int i = 0;
         vector<string>ans;
        helper(s, temp, i, 0, ans);
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}
// } Driver Code Ends