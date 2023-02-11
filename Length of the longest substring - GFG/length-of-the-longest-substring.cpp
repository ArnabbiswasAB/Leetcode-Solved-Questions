//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string s){
        //code
        
        vector<int>mp(256,-1);
        int ans = 0, i = 0, j = 0, n = s.length();
        
        while(i<n){
            
            if(mp[s[i]] != -1)
              j = max(mp[s[i]]+1,j);
              
              
              mp[s[i]] = i;
              ans = max(ans, i - j + 1);
              i++;
        }
        
        return ans;
        
        
    /*    vector<int>mp(256,0);
        int ans = 0, i = 0, j = 0, n = s.length();
        
        
        while(i<n){
           
           mp[s[i] - 'a']++;
           
           while(mp[s[i] - 'a'] > 1){
               mp[s[j] - 'a']--;
               j++;
           }
           
           ans = max(ans, i - j + 1);
           i++;
        }
        
        
        return ans;
        */
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends