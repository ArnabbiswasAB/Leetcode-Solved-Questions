//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        
        int counter = p.size();
        int start=0, end=0, minStart=0, n=s.length(), len = INT_MAX;
        unordered_map<char,int>mp;
        
        for(int i=0; i<p.length(); i++)
          mp[p[i]]++;
          
        while(end<n){
            
          if(mp[s[end]] > 0)
          counter--;
          
          mp[s[end]]--;
          end++;
          
          while(counter == 0){
              
              if(end - start < len){
                  len = end - start;
                  minStart = start;
              }
              
              mp[s[start]]++;
              if(mp[s[start]] > 0)
              counter++;
              
              start++;
          }
        }
        
        
        return len == INT_MAX ? "-1" : s.substr(minStart,len);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends