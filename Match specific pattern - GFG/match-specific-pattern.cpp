//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<string> findMatchedWords(vector<string> dict,string pattern);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> s(n);
		for(int i=0;i<n;i++)
		    cin>>s[i];
		
		string tt;
		cin>>tt;
		
		vector<string> res = findMatchedWords(s,tt);
        sort(res.begin(),res.end());
		for(int i=0;i<res.size();i++)
		    cout<<res[i]<<" ";
		cout<<endl;
		
	}
}
// } Driver Code Ends



void helper(string s, string p, vector<string> &ans){
    
    if(s.length() != p.length())
    return;
    
    unordered_set<char>st;
    unordered_map<char,char>mp;
    
    for(int i=0; i<s.length(); i++){
        
        if(mp.find(s[i]) != mp.end()){
            if(mp[s[i]] != p[i])
            return;
            
        }else{
            if(st.find(p[i]) != st.end())
            return;
            
            mp[s[i]] = p[i];
            st.insert(p[i]);
        }
    }
    
    ans.push_back(s);
    
    return;
}

vector<string> findMatchedWords(vector<string> dict,string pattern)
{
       //Your code here
       
       vector<string>ans;
       
       for(auto it : dict){
           helper(it, pattern, ans);
       }
       
       return ans;
}