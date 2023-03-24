//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
   
    void helper(string s,string temp,vector<int>& vis,vector<string>& ans){
        
        if(temp.length() == s.length()){
            ans.push_back(temp);
            return;
        }
        
        for(int i=0; i<s.length(); i++){
            
            if(vis[i] == -1){
                temp.push_back(s[i]);
                vis[i] = 1;
                helper(s, temp, vis, ans);
                temp.pop_back();
                vis[i] = -1;
            }
        }
    } 
    
    vector<string> permutation(string s)
    {
        //Your code here
        vector<string>ans;
        int n = s.length();
        vector<int>vis(n,-1);
        helper(s,"", vis, ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends