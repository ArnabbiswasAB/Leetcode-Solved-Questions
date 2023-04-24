//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	set<string>st;
	
	    void helper(string s,int n,vector<int>& curr,string temp,vector<string>& ans){
	        
	       if(temp.size() == s.size()){
	            
	            if(st.find(temp) == st.end())
	            ans.push_back(temp);
	            
	            st.insert(temp);
	            return;
	        }
	        
	        
	        for(int i=0; i<n; i++){
	            
	            if(curr[i] == -1){
	                temp.push_back(s[i]);
	                curr[i] = 1;
	                helper(s,n, curr, temp, ans);
	                temp.pop_back();
	                curr[i] = -1;
	            }
	        }
	    }
	    
		vector<string>find_permutation(string s)
		{
		    // Code here there
		    int n = s.length();
		    vector<int> curr(n,-1);
		    vector<string>ans;
		    
		    helper(s,n,curr,"",ans);
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