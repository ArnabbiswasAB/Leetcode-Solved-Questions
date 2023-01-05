//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	  set<string>st;
	  
	    void findWays(string s,vector<int>&vis, vector<string> &ans,string temp, int n){
	        
	        if(temp.size() == s.size()){
	            
	            if(st.find(temp) == st.end())
	            ans.push_back(temp);
	            
	            st.insert(temp);
	            return;
	        }
	        
	        
	        for(int i=0; i<n; i++){
	            
	           
	            
	            if(vis[i] == -1){
	                vis[i] = 1;
	                temp += s[i];
	                findWays(s, vis, ans, temp, n);
	                temp.pop_back();
	                vis[i] = -1;
	            }
	        }
	    }
	    
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string>ans;
		    int n = S.size();
		    
		    vector<int>vis(n,-1);
		    string temp = "";
		    findWays(S,vis,ans,temp,n);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends