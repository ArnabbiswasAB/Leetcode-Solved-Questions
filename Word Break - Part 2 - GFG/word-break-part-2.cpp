//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<string>ans;
    void helper(int i,string s,string sentence,unordered_map<string,int>& mp){
     
       if(i >= s.size()){
           if(sentence.back() == ' ')
             sentence.pop_back();
             
          ans.push_back(sentence);
          return;
       }
       
       string temp = "";
       for(int j=i; j<s.size(); j++){
           
           temp.push_back(s[j]);
           
           if(mp.find(temp) != mp.end()){
               helper(j+1,s,sentence + temp + ' ', mp);
           }
       }
    }
    
    
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        unordered_map<string,int>mp;
        for(auto it : dict){
            mp[it]++;
        }
        
        helper(0,s,"",mp);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends