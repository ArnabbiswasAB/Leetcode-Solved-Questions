//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string t)
    {
        // Your code here
        unordered_map<char,int>mp;
        int minlen=INT_MAX, end=0, start=0, size = s.size(),minstart=0;
        
        for(int i=0; i<t.size(); i++)
        mp[t[i]]++;
        
        int counter=t.size();
        
        while(end<size){
            
            if(mp[s[end]] > 0)
               counter--;
               
            mp[s[end]]--;
            end++;
            
            while(counter == 0){
                
                if(end - start < minlen){
                    minstart=start;
                    minlen = end - start;
                }
                
                mp[s[start]]++;
                
                if(mp[s[start]] > 0)
                counter++;
                
                start++;
            }
        }
        
        if(minlen != INT_MAX)
        return s.substr(minstart, minlen);
        
        return "-1";
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